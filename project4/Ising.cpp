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

// Setting up a random initial spin state
void initialize(mat &spin, int n, double &E, double &M) {

  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      // spin(x, y) = gen_random();
      spin(x, y) = 1;
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
    acceptAmp.insert(pair<double, double>(de, exp(-1 / T * (de))));
  }

  return acceptAmp;
}

// Flipps a random spin according to acceptence requirements
void tryflip(mat &spin, int n, int Delta_E, map<double, double> W, int rx,
             int ry, double &E, double &M, mt19937_64 &generator) {
  uniform_int_distribution<int> dist(0, 1);
  double r = dist(generator);
  if (r <= W.find(Delta_E)->second) {
    spin(rx, ry) *= -1;
    // cout << "Flipp" << endl;
    M += (double)2 * spin(rx, ry);
    E += (double)Delta_E;
  }
  // else {
  // cout << "No flipp" << endl;
  // }
}

// Metropolis algorithm
void Metropolis(mat &spin, double T, int L, map<double, double> W, double &E,
                double &M, mt19937_64 &generator) {

  double J = 1;
  for (int x = 0; x < L; x++) {
    for (int y = 0; y < L; y++) {
      int rx = rand() % L;
      int ry = rand() % L;
      int Delta_E = 2 * J * spin(rx, ry) *
                    (spin(rx, PBC(ry, L, 1)) + spin(PBC(ry, L, 1)) +
                     spin(rx, PBC(ry, L, -1)) + spin(PBC(ry, L, -1)));
      tryflip(spin, L, Delta_E, W, rx, ry, E, M, generator);
    }
  }
  return;
}

// Writing array to binary file
// void writebinary(int E) {
//   // streampos size;
//   ofstream outfile;
//   outfile.open("mean_energy.dat", ios::out | ios::app | ios::binary);
//   // outfile.write((char *)&E, sizeof(double));
//   outfile.write(reinterpret_cast<const char *>(E), sizeof(E));
//   outfile.close();
//   return;
// }

// Monte Carlo simulation
void MC(mat &spin, double T, int L, double &E, double &M, int mcs) {
  int *averages = new int[mcs];
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  mt19937_64 generator(seed);
  // vec averages(4);
  for (int cycle = 0; cycle < mcs; cycle++) {
    map<double, double> W = transitions(T);
    Metropolis(spin, T, L, W, E, M, generator);
    averages[cycle] = E;
    // cout << averages[cycle] << endl;
  }
  ofstream outfile;
  outfile.open("mean_energy.dat", ios::out | ios::app | ios::binary);
  // outfile.write((char *)&E, sizeof(double));
  outfile.write(reinterpret_cast<const char *>(averages), mcs * sizeof(int));
  outfile.close();
  return;
}

int main(int argc, char const *argv[]) {
  int temp_start = atoi(argv[1]);
  int temp_stop = atoi(argv[2]);
  int temp_step = atoi(argv[3]);
  int mcs = atoi(argv[4]);
  // int L = atoi(argv[5]);
  // srand(time(NULL));

  int L = 2;
  mat spin = zeros(L, L);
  double E, M;
  double T = 2.0;
  E = 0;
  M = 0;
  initialize(spin, L, E, M);

  // for (int T = temp_start; T < temp_stop; T += temp_step) {
  MC(spin, T, L, E, M, mcs);
  // }
  // writebinary(averages);

  return 0;
}
