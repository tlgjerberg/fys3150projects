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
void initialize(mat &spin, int n, double T, double &E, double &M) {

  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      spin(x, y) = gen_random();
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
             int ry, double &E, double &M) {
  if (rand() % 2 <= W.find(Delta_E)->second) {
    spin(rx, ry) *= -1;
    cout << "Flipp" << endl;
    M += (double)spin(rx, ry);
    E += (double)Delta_E;
  } else {
    cout << "No flipp" << endl;
  }
}

// Metropolis algorithm
void Metropolis(mat &spin, double T, int n, map<double, double> W, double &E,
                double &M) {
  double J = 1;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      int rx = rand() % n;
      int ry = rand() % n;
      int Delta_E = 2 * J * spin(rx, ry) *
                    (spin(rx, PBC(ry, n, 1)) + spin(PBC(ry, n, 1)) +
                     spin(rx, PBC(ry, n, -1)) + spin(PBC(ry, n, -1)));
      tryflip(spin, n, Delta_E, W, rx, ry, E, M);
    }
  }
  return;
}

void writebinary(double &E) {
  streampos size;
  // char *memblock;
  ofstream outfile;
  outfile.open("mean_energy.bin", ios::out | ios::app | ios::binary);
  // outfile.seekp(0, ios::beg);
  outfile.write((char *)&E, sizeof(double));
  // delete[] memblock;
  outfile.close();
  return;
}

int main(int argc, char const *argv[]) {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  // srand(time(NULL));
  mt19937 generator(seed);
  // int r = gen_random();
  // cout << r << endl;
  int L = 2;
  mat spin = zeros(L, L);
  double E, M;
  double T = 2.0;
  E = 0;
  M = 0;
  vec w(5);
  initialize(spin, L, T, E, M);
  // cout << spin << endl;
  // flip_one(spin, 0, 1);
  // cout << spin << endl;
  map<double, double> W = transitions(T);
  cout << W.find(4)->second << endl;
  Metropolis(spin, T, L, W, E, M);
  cout << E << endl;
  cout << M << endl;
  writebinary(E);
  return 0;
}
