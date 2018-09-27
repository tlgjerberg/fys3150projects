#include "jacobi.h"

int main(int argc, char const *argv[]) {

  int n = atoi(argv[1]);
  double rho_N = 10;
  double rho_0 = 0;
  double h = (rho_N - rho_0) / n;
  double hh = h * h;

  vec rho = linspace(1, n, n) * h;

  mat A = HO_toeplitz(n, hh, rho);

  vec eigval;
  mat eigvec;

  eig_sym(eigval, eigvec, A);

  int k, l;
  double eps = 1e-8;
  double max = maxoffdiag(A, k, l, n);
  clock_t c_start = clock();

  vec jacobi_eigval = jacobi_method(A, eps, max, k, l, n);

  clock_t c_end = clock();

  for (int i = 0; i < 4; i++) {
    // cout << eigval[i] << endl;
    cout << jacobi_eigval[i] << endl;
  }
  cout << fixed << "CPU time used with Jacobi's method: "
       << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms\n";

  return 0;
}
