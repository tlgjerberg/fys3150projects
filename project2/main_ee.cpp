#include "jacobi.h"

int main(int argc, char const *argv[]) {

  int n = atoi(argv[1]);
  double omega_r = atof(argv[2]);
  double rho_N = atof(argv[3]);
  double rho_0 = 0;
  double h = (rho_N - rho_0) / n;
  double hh = h * h;

  vec rho = linspace(1, n, n) * h;

  mat A = HO_toeplitz_coulomb(n, hh, rho, omega_r);

  vec eigval;
  mat eigvec;

  eig_sym(eigval, eigvec, A);

  cout << eigval << endl;
  // cout << eigvec << endl;

  mat R = zeros(n, n);
  R.diag() += 1;

  int k, l;
  double eps = 1e-8;
  double max = maxoffdiag(A, k, l, n);
  clock_t c_start = clock();

  vec jacobi_eigval = jacobi_method(A, R, eps, max, k, l, n);

  clock_t c_end = clock();

  // for (int i = 0; i < 4; i++) {
  //   cout << jacobi_eigval[i] << endl;
  // }
  cout << jacobi_eigval << endl;
  cout << fixed << "CPU time used with Jacobi's method: "
       << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms\n";

  ofstream ofile;

  ofile.open("eigenvectors.txt");
  for (int i = 0; i < n; i++) {
    ofile << rho[i] << " " << R(0, i) << endl;
    // ofile << rho << " ";
    // ofile << R(span::all, 0) << endl;
  }
  ofile.close();

  return 0;
}
