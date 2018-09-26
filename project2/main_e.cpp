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

  vec eigval;
  mat eigvec;

  eig_sym(eigval, eigvec, A);

  cout << eigval << endl;

  int k, l;
  double eps = 1e-8;
  double max = maxoffdiag(A, k, l, n);
  clock_t c_start = clock();

  vec jacobi_eigval = jacobi_method(A, eps, max, k, l, n);

  clock_t c_end = clock();

  double hbar = 4.135667662e-15;
  double alpha = 2;
  double omega = 2;
  double m = 9.10938356e-31;
  double k_scale = m * omega * omega;

  cout << jacobi_eigval << endl;
  cout << fixed << "CPU time used with Jacobi's method: "
       << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms\n";

  return 0;
}
