#include "jacobi.h"

vec analytic_eigenvalues_buckling_beam(int n, double hh) {
  double d = 2 / hh;
  double a = -1 / hh;
  double pi = M_PI;
  vec lambda = zeros(n);
  for (int j = 1; j < n - 1; j++) {
    lambda[j] = d + 2 * a * cos((j * pi) / (n + 1));
  }
  return lambda;
}

int main(int argc, char const *argv[]) {

  int n = atoi(argv[1]);
  double rho_N = 1;
  double rho_0 = 0;
  double h = (rho_N - rho_0) / n;
  double hh = h * h;

  mat A = toeplitz(n, hh);

  vec eigval;
  mat eigvec;

  eig_sym(eigval, eigvec, A);

  mat R = zeros(n, n);
  R.diag() += 1;

  int k, l;
  double eps = 1e-8;
  double max = maxoffdiag(A, k, l, n);
  clock_t c_start = clock();

  vec jacobi_eigval = jacobi_method(A, R, eps, max, k, l, n);

  clock_t c_end = clock();

  cout << fixed << "CPU time used with Jacobi's method: "
       << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms\n";

  vec analytic_eigval = analytic_eigenvalues_buckling_beam(n, hh);

  ofstream ofile;

  ofile.open("eigenvalues.txt");

  ofile << "analytic_eigval"
        << " "
        << "jacobi_eigval" << endl;
  for (int i = 0; i < n; i++) {
    ofile << analytic_eigval[i] << " " << jacobi_eigval[i] << " " << endl;
    // ofile << rho << " ";
    // ofile << R(span::all, 0) << endl;
  }
  ofile.close();

  return 0;
}
