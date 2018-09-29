#include "jacobi.h"

int main(int argc, char const *argv[]) {

  int n = atoi(argv[1]);
  double rho_N = 1;
  double rho_0 = 0;
  double h = (rho_N - rho_0) / n;
  double hh = h * h;

  mat A = toeplitz(n, hh);

  vec arma_eigval;
  mat arma_eigvec;

  clock_t arma_start = clock();

  eig_sym(arma_eigval, arma_eigvec, A);

  clock_t arma_end = clock();

  mat R = zeros(n, n);
  R.diag() += 1;

  int k, l;
  double eps = 1e-8;
  double max = maxoffdiag(A, k, l, n);
  clock_t c_start = clock();

  vec jacobi_eigval = jacobi_method(A, R, eps, max, k, l, n);

  clock_t c_end = clock();

  cout << fixed << "CPU time used with Armadillo eig_sym method: "
       << 1000.0 * (arma_end - arma_start) / CLOCKS_PER_SEC << " ms\n";
  cout << fixed << "CPU time used with Jacobi's method: "
       << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms\n";

  vec analytic_eigval = analytic_eigenvalues_buckling_beam(n, hh);

  /*Printing the three sets of eigenvalues computed analytically, with Armadillo
and with jacobi's method */
  ofstream ofile;

  ofile.open("eigenvalues.txt");

  ofile << "analytic_eigval"
        << " "
        << "arma_eigval"
        << " "
        << "jacobi_eigval" << endl;
  for (int i = 0; i < n; i++) {
    ofile << analytic_eigval[i + 1] << " " << arma_eigval[i] << " "
          << jacobi_eigval[i] << endl;
  }
  ofile.close();

  return 0;
}
