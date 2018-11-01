#include <armadillo>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
using namespace arma;

void tryflip(mat &spin, int n, int Delta_E, vec w, int rx, int ry) {
  if (rand() <= w[Delta_E]) {
    spin(rx, ry) *= -1;
  }
}

void Metropolis(mat &spin, double T, int n, vec w) {
  double J = 1;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      int rx = rand() % n;
      int ry = rand() % n;
      int Delta_E = 2 * J * spin(x, y);
      tryflip(spin, n, Delta_E, w, rx, ry);
    }
  }

  return;
}

void flip_one(mat &spin, int xf, int yf) {
  spin(xf, yf) += -1;
  return;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
