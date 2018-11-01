#include <armadillo>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>

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

int PBC() {}

// Setting up a random initial spin state
void initialize(mat &spin, int n, double T, double &E, double &M) {

  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      spin(x, y) = gen_random();
      M += spin(x, y);
      E -= 1;
    }
  }

  return;
}

void flip_one(mat &spin, int xf, int yf) {
  spin(xf, yf) *= -1;
  return;
}

// void tryflip(mat &spin, int n, int Delta_E, vec w) {
//   for (int x = 0; x < n; x++) {
//     for (int y = 0; y < n; y++) {
//       if (rand() <= w[Delta_E]) {
//         spin(x, y) *= -1;
//       }
//     }
//   }
// }

// Method for finding the possible energy transitions Delta_E
map<double, double> transitions(double T, vec w) {
  map<double, double> acceptAmp;

  for (int i = 0; i < 5; i++) {
    for (int de = -8; de <= 8; de += 4) {
      acceptAmp.insert(pair<double, double>(de, exp(-1 / T * (de))));
      // if (abs(de) % 4 == 0) {

      // w[i] = exp(-de / T);
      // }
    }
  }

  return acceptAmp;
}

void tryflip(mat &spin, int n, int Delta_E, vec w, int rx, int ry) {
  if (rand() <= w[Delta_E]) {
    spin(rx, ry) *= -1;
    cout << "Flipped" << endl;
  } else {
    cout << "No flipp" << endl;
  }
}

void Metropolis(mat &spin, double T, int n, vec w) {
  double J = 1;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      int rx = rand() % n;
      int ry = rand() % n;
      int Delta_E = 2 * J * spin(rx, ry) * (1);
      tryflip(spin, n, Delta_E, w, rx, ry);
    }
  }

  return;
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  // int r = gen_random();
  // cout << r << endl;
  int n = 2;
  mat spin = zeros(n, n);
  double E, M;
  double T = 2.0;
  E = 0;
  M = 0;
  vec w(5);
  initialize(spin, n, T, E, M);
  // cout << spin << endl;
  flip_one(spin, 0, 1);
  // cout << spin << endl;
  map<double, double> W = transitions(T, w);
  cout << W.find(4)->second << endl;
  // Metropolis(spin, T, n, W);

  return 0;
}
