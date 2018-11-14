#include "Ising.h"

//==============================================================================
// Gives a random number either -1 or 1
//==============================================================================
int gen_random() {
  int ran_num = rand() % 2;
  if (ran_num == 0) {
    ran_num = -1;
  }
  return ran_num;
}
//==============================================================================
// Periodic boundry conditions
//==============================================================================
int PBC(int i, int limit, int add) { return (i + limit + add) % (limit); }

//==============================================================================
// Setting up the initial spin state
//==============================================================================
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
  // Initial energy and magentic momentum
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {

      M += (double)spin(x, y);
      E -= (double)spin(x, y) *
           (spin(PBC(x, n, -1), y) + spin(x, PBC(y, n, -1)));
    }
  }
  return;
}

//==============================================================================
// Flipps the one spin of choice
//==============================================================================
void flip_one(mat &spin, int xf, int yf) {
  spin(xf, yf) *= -1;
  return;
}

//==============================================================================
// Method for finding the possible energy transitions Delta_E
//==============================================================================
map<double, double> transitions(double T) {
  map<double, double> acceptAmp; // Dictionary-like data structure

  for (int de = -8; de <= 8; de += 4) {
    // Inserts the value of the exponential at the "key" de
    acceptAmp.insert(pair<double, double>(de, exp(-de / T)));
  }
  return acceptAmp;
}
//==============================================================================
// Flipps a random spin according to the Metropolis selction rule
//==============================================================================
void tryflip(mat &spin, int n, int Delta_E, map<double, double> W, int rx,
             int ry, double &E, double &M, mt19937 &generator) {

  uniform_real_distribution<float> uni_dist(0, 1);
  double r = uni_dist(generator);
  // Metropolis test
  if (r <= W.find(Delta_E)->second) {
    spin(rx, ry) *= -1;

    M += (double)2 * spin(rx, ry);
    E += (double)Delta_E;
  }
}
//==============================================================================
// Metropolis algorithm
//==============================================================================
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
//==============================================================================
// Monte Carlo simulation
//==============================================================================
void MC(mat &spin, double T, int L, int mcs, int GS, int *energies,
        vec &ExpectVals) {
  double E, M;
  E = M = 0;
  initialize(spin, L, E, M, GS);

  // Setting up the RNG with a seed determined from the machine clock
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  mt19937 generator(seed);

  map<double, double> W = transitions(T); // Allowed transitions for

  for (int cycle = 1; cycle < mcs; cycle++) {
    Metropolis(spin, T, L, W, E, M, generator);
    energies[cycle] = E;
    addexpect(ExpectVals, E, M);
  }
  return;
}
//==============================================================================
// Adding up all values of energy and momentum to their respective expectation
// values
//==============================================================================
void addexpect(vec &ExpectVals, double &E, double &M) {
  ExpectVals(0) += E;
  ExpectVals(1) += E * E;
  ExpectVals(2) += M;
  ExpectVals(3) += M * M;
  ExpectVals(4) += fabs(M);
  return;
}

void printexpect(vec &TotalExpectVals, double T, int mcs) {
  double norm = 1 / ((double)(mcs));
  TotalExpectVals *= norm;
  cout << "<E>: " << TotalExpectVals(0) << " ";
  cout << "<M>: " << TotalExpectVals(4) << " ";
  cout << "C_V: "
       << (TotalExpectVals(1) - pow(TotalExpectVals(0), 2)) / (pow(T, 2))
       << " ";
  cout << "Chi: " << (TotalExpectVals(3) - pow(TotalExpectVals(2), 2)) / T
       << " " << endl;

  return;
}
