#include "jacobi.h"

/* Create program with: make elec */
/* Run ./elec.o with command line argument n and rho_N */

void write_eigenvector_to_file(vec rho, mat R, int n) {

  ofstream ovecfile;

  ovecfile.open("eigenvectors_d.txt", ofstream::app);

  // ovecfile << "rho"
  //          << " "
  //          << "eigenvector" << endl;
  for (int i = 0; i < n; i++) {
    ovecfile << rho[i] << " " << R(i, 0) << endl;
  }
  ovecfile.close();
  return;
}

int main(int argc, char const *argv[]) {

  int n = atoi(argv[1]);
  double rho_N = atoi(argv[2]);
  double rho_0 = 0;
  double h = (rho_N - rho_0) / n;
  double hh = h * h;

  vec rho = linspace(1, n, n) * h;

  mat A = HO_tridiag(n, hh, rho);

  vec eigval;
  mat eigvec;

  eig_sym(eigval, eigvec, A);

  mat R = zeros(n, n); // Matrix for storing eigenvectors
  R.diag() += 1;

  int k, l;
  double eps = 1e-8;
  double max = maxoffdiag(A, k, l, n);
  /* Jacobi method for diagonalizing and finding the eigenvalues.
  See jacobi.cpp and maxoffdiag.cpp for the computation */
  clock_t c_start = clock();

  vec jacobi_eigval = jacobi_method(A, R, eps, max, k, l, n);

  clock_t c_end = clock();

  cout << fixed << "CPU time used with Jacobi's method: "
       << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms\n";

  ofstream ofile;

  ofile.open("eigenvalues_d.txt");

  for (int i = 0; i < 4; i++) {
    ofile << jacobi_eigval[i] << endl;
  }

  ofile.close();

  write_eigenvector_to_file(rho, R, n);

  return 0;
}
