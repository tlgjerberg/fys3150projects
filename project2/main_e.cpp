#include "jacobi.h"
#include <armadillo>
#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;
using namespace arma;

int main(int argc, char const *argv[]) {
  int n = atoi(argv[1]);
  double rho_N = 10;
  double rho_0 = 0;
  double h = (rho_N - rho_0) / n;
  double hh = h * h;

  vec rho = linspace(rho_0 + h, n);

  mat A = HO_toeplitz(n, hh, rho);

  cout << A << endl;

  return 0;
}
