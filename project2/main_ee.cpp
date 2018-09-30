#include "jacobi.h"

/* Writing rho, the eigenvectors from the jacobi method and the eigenvectors
  the armadillo eig_sym function produces  to a file eigenvector.txt */
void write_eigenvector_to_file(vec rho, mat R, mat eigvec, int n) {

  ofstream ovecfile;

  ovecfile.open("eigenvectors_e.txt", ofstream::app);

  ovecfile << "rho"
           << " "
           << "eigenvector" << endl;
  for (int i = 0; i < n; i++) {
    ovecfile << rho[i] << " " << R(i, 0) << endl;
  }
  ovecfile.close();
  return;
}

void write_eigenvalues_to_file(vec jacobi_eigval, vec eigval, int n,
                               double omega_r) {

  ofstream ovalfile;

  ovalfile.open("eigenvalues_e.txt", ofstream::app);

  // ovalfile << "omega_r"
  //          << " "
  //          << "eigenvalues" << endl;
  ovalfile << omega_r << " " << jacobi_eigval[0] << endl;
  ovalfile.close();
  return;
}

int main(int argc, char const *argv[]) {

  int n = atoi(argv[1]);
  double omega_r = atof(argv[2]);
  double rho_N = atof(argv[3]);
  double rho_0 = 0;
  double h = (rho_N - rho_0) / n;
  double hh = h * h;

  vec rho = linspace(1, n, n) * h;

  mat A = HO_toeplitz_coulomb(n, hh, rho, omega_r);

  vec arma_eigval;
  mat arma_eigvec;

  eig_sym(arma_eigval, arma_eigvec, A);

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

  // Printing the first four eigenvalues from the jacobi method
  for (int i = 0; i < 4; i++) {
    cout << jacobi_eigval[i] << endl;
  }

  cout << fixed << "CPU time used with Jacobi's method: "
       << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms\n";

  /*Printing eigenvectors and eigenvalues to the files*/
  write_eigenvector_to_file(rho, R, arma_eigvec, n);
  write_eigenvalues_to_file(jacobi_eigval, arma_eigval, n, omega_r);

  return 0;
}
