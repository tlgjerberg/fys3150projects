#include "mpi.h"
#include <armadillo>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <random>

using namespace std;
using namespace arma;

// Gives a random number either -1 or 1
int gen_random() {
  int ran_num = rand() % 2;
  if (ran_num == 0) {
    ran_num = -1;
  }
  return ran_num;
}

// Periodic boundry conditions
int PBC(int i, int limit, int add) { return (i + limit + add) % (limit); }

// Setting up the initial spin state
void initialize(mat &spin, int n, double &E, double &M, int GS) {
  // Setting up the ground state
  if (GS == 1) {
    spin.fill(1);

  } else {
    // Setting up a state with randomly pointing spins
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < n; y++) {
        spin(x, y) = gen_random();
      }
    }
  }

  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {

      M += (double)spin(x, y);
      E -= (double)spin(x, y) *
           (spin(PBC(x, n, -1), y) + spin(x, PBC(y, n, -1)));
    }
  }
  return;
}

// Flipps the one spin of choice
void flip_one(mat &spin, int xf, int yf) {
  spin(xf, yf) *= -1;
  return;
}

// Method for finding the possible energy transitions Delta_E
map<double, double> transitions(double T) {
  map<double, double> acceptAmp; // Dictionary-like data structure

  for (int de = -8; de <= 8; de += 4) {
    // Inserts the value of the exponential at the "key" de
    acceptAmp.insert(pair<double, double>(de, exp(-de / T)));
  }
  return acceptAmp;
}

// Flipps a random spin according to the Metropolis selction rule
void tryflip(mat &spin, int n, int Delta_E, map<double, double> W, int rx,
             int ry, double &E, double &M, mt19937 &generator) {

  uniform_real_distribution<float> dist(0, 1);
  double r = dist(generator);
  // Metropolis test
  if (r <= W.find(Delta_E)->second) {
    spin(rx, ry) *= -1;

    M += (double)2 * spin(rx, ry);
    E += (double)Delta_E;
  }
}

// Metropolis algorithm
void Metropolis(mat &spin, double T, int L, map<double, double> W, double &E,
                double &M, mt19937 &generator) {
  uniform_int_distribution<int> rand_spin(0, L - 1);
  for (int x = 0; x < L; x++) {
    for (int y = 0; y < L; y++) {
      int rx = rand_spin(generator);
      int ry = rand_spin(generator);
      int Delta_E = 2 * spin(rx, ry) *
                    (spin(rx, PBC(ry, L, -1)) + spin(PBC(rx, L, -1), ry) +
                     spin(rx, PBC(ry, L, 1)) + spin(PBC(rx, L, 1), ry));
      tryflip(spin, L, Delta_E, W, rx, ry, E, M, generator);
    }
  }
  return;
}

// Monte Carlo simulation
void MC(mat &spin, double T, int L, double &E, double &M, int mcs, int GS,
        int *averages, int numprocs, int my_rank) {

  int no_intervalls = mcs / numprocs;
  int myloop_begin = my_rank * no_intervalls + 1;
  int myloop_end = (my_rank + 1) * no_intervalls;
  initialize(spin, L, E, M, GS);

  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  mt19937 generator(seed);

  for (int cycle = myloop_begin; cycle < myloop_end; cycle++) {
    map<double, double> W = transitions(T);
    Metropolis(spin, T, L, W, E, M, generator);
    averages[cycle] = E;
  }
  return;
}

int main(int argc, char *argv[]) {
  char *outfilename = argv[1];
  int initial_temp = atoi(argv[2]);
  int final_temp = atoi(argv[3]);
  int temp_step = atoi(argv[4]);
  int mcs = atoi(argv[5]);
  int L = atoi(argv[6]);

  int numprocs, my_rank;
  mat spin = zeros(L, L);
  double E, M;
  E = 0;
  M = 0;
  int GS = 1;

  ofstream outfile;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

  // broadcast to all nodes common variables
  // MPI_Bcast(&L, 1, MPI_INT, 0, MPI_COMM_WORLD);
  // MPI_Bcast(&initial_temp, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  // MPI_Bcast(&final_temp, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  // MPI_Bcast(&temp_step, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

  // for (int T = initial_temp; T < final_temp; T += temp_step) {
  double T = 1.0;
  int *averages;
  averages = new int[mcs];
  MC(spin, T, L, E, M, mcs, GS, averages, numprocs, my_rank);
  if (my_rank == 0) {
    MPI_Status status;
    outfile.open(outfilename, ios::binary);
    outfile.write(reinterpret_cast<const char *>(averages), mcs * sizeof(int));

    for (int i = 1; i < numprocs; i++) {
      MPI_Recv(averages, mcs, MPI_INT, MPI_ANY_SOURCE, 500, MPI_COMM_WORLD,
               &status);
      outfile.write(reinterpret_cast<const char *>(averages),
                    mcs * sizeof(int));
    }

    outfile.close();
  } else {
    MPI_Send(averages, mcs, MPI_INT, 0, 500, MPI_COMM_WORLD);
  }
  MPI_Finalize();
  // delete averages;
  // delete[] averages;
  // }

  return 0;
}
