#include <armadillo>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
using namespace arma;

int gen_random() {
  int ran_num = rand() % 2;
  if (ran_num == 0) {
    ran_num = -1;
  }
  return ran_num;
}

void flip_one(mat &spin, double &E, double &M) {}

void initialize(mat &spin, int n, double T, double &E, double &M) {

  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      spin(x, y) = gen_random();
      M += spin(x, y);
    }
  }

  return;
}

void Metropolis(double T) { return; }

// Method for finding the possible energy transitions Delta_E
vec transitions(double T) {
  vec w(17);

  for (int de = -8; de <= 8; de++)
    w[de + 8] = 0;
  for (int de = -8; de <= 8; de += 4)
    w[de + 8] = exp(-de / T);

  return w;
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  // int r = gen_random();
  // cout << r << endl;
  int n = 2;
  mat spin = zeros(n, n);
  double E, M;
  double T = 1.0;
  E = 0;
  M = 0;
  initialize(spin, n, T, E, M);
  cout << spin << endl;
  vec W = transitions(T);
  cout << W << endl;
  return 0;
}
