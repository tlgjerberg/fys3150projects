#include "jacobi.h"

/* Preforms a jacobi rotation of a matrix A and a matrix of eigenvectors R*/
void rotation(mat &A, mat &R, int &k, int &l, int n) {

  double c, s;
  double t, tau;

  if (A(k, l) != 0.0) {
    tau = (A(l, l) - A(k, k)) / (2 * A(k, l));
    double t1, t2;
    t1 = 1 / (tau + sqrt(1 + tau * tau));
    t2 = -1 / (-tau + sqrt(1 + tau * tau));

    // Minimizing t
    if (fabs(t1) < fabs(t2)) {
      t = t1;
    } else {
      t = t2;
    }
    c = 1 / sqrt(1 + t * t);
    s = t * c;
  } else {
    c = 1.0;
    s = 0.0;
  }

  double akk = A(k, k);
  double all = A(l, l);
  double aik, ail;
  A(k, k) = akk * c * c - 2 * A(k, l) * c * s + all * s * s;
  A(l, l) = all * c * c + 2 * A(k, l) * c * s + akk * s * s;
  A(k, l) = A(l, k) = 0.0;

  for (int i = 0; i < n; i++) {
    if (i != k && i != l) {
      aik = A(i, k);
      ail = A(i, l);
      A(i, k) = aik * c - ail * s;
      A(k, i) = A(i, k);
      A(i, l) = ail * c + aik * s;
      A(l, i) = A(i, l);
    }
    double rik = R(i, k);
    double ril = R(i, l);
    R(i, k) = c * rik - s * ril;
    R(i, l) = c * ril + s * rik;
  }
  return;
}

/* Loops over the unsorted vector of eigenvalues and sorts eigenvalues and
eigenvectors from smallest to largest eigenvalue */
vec eigenpairs(mat &R, vec eigvals, int n) {
  double temp = 0.0;
  vec temp_vec = zeros(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (eigvals[j] > eigvals[i]) {
        temp = eigvals[i];
        temp_vec = R(span::all, i);
        eigvals[i] = eigvals[j];
        R(span::all, i) = R(span::all, j);
        eigvals[j] = temp;
        R(span::all, j) = temp_vec;
      }
    }
  }
  return eigvals;
}

/* Main loop calling on maxoffdiag(), rotation() and eigenpairs() to preform
jacobi's method and sorting the eigenpairs */
vec jacobi_method(mat A, mat &R, double eps, double max, int k, int l, int n) {
  int max_iter = (double)n * (double)n * (double)n;
  int iter = 0;
  while (max > eps && iter < max_iter) {
    max = maxoffdiag(A, k, l, n);
    rotation(A, R, k, l, n);
    iter++;
  }
  cout << "Number of iterations: " << iter << endl;
  vec eigvals = diagvec(A);
  vec eigvals_sorted = eigenpairs(R, eigvals, n);
  return eigvals_sorted;
}
