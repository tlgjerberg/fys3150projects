#include "jacobi.h"
#include "maxoffdiag.h"
#include "toeplitz.h"
#include <armadillo>
#include <cmath>
#include <ctime>
#include <iostream>
using namespace std;
using namespace arma;

int main(int argc, char const *argv[]) {

  int n = atoi(argv[1]);
  double rho_N = 1;
  double rho_0 = 0;
  double h = (rho_N - rho_0) / n;
  double hh = h * h;

  mat A = toeplitz(n, hh);

  // cout << A << endl;

  vec eigval;
  mat eigvec;

  eig_sym(eigval, eigvec, A);

  cout << eigval << endl;
  clock_t c_start = clock();
  int k, l;
  double eps = 1e-8;
  double max = maxoffdiag(A, k, l, n);
  int max_iter = (double)n * (double)n * (double)n;
  int iter = 0;
  while (max > eps && iter < max_iter) {
    max = maxoffdiag(A, k, l, n);
    rotation(A, k, l, n);
    iter++;
  }
  clock_t c_end = clock();

  vec jacobi_eigval = diagvec(A);

  cout << jacobi_eigval << endl;
  cout << "Number of iterations: " << iter << endl;
  cout << fixed << "CPU time used with Jacobi's method: "
       << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms\n";
  return 0;
}
