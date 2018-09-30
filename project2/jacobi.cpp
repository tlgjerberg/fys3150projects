#include "jacobi.h"

/* Computes the eigenvalues og the bukling beam from the known analytical
  expression*/
vec analytic_eigenvalues_buckling_beam(int n, double hh) {
  double d = 2 / hh;
  double a = -1 / hh;
  double pi = M_PI;
  vec lambda = zeros(n);
  for (int j = 1; j < n; j++) {
    lambda[j] = d + 2 * a * cos((j * pi) / (n + 1));
  }
  return lambda;
}

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
  // Rotating the matrix with A(k, l) as the largest off-diagonal element
  double cc, ss, cs;
  cc = c * c;
  ss = s * s;
  cs = c * s;
  double akk = A(k, k);
  double all = A(l, l);
  double aik, ail;
  A(k, k) = akk * cc - 2 * A(k, l) * cs + all * ss;
  A(l, l) = all * cc + 2 * A(k, l) * cs + akk * ss;
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
    // Computing the eigenvectors
    double rik = R(i, k);
    double ril = R(i, l);
    R(i, k) = c * rik - s * ril;
    R(i, l) = c * ril + s * rik;
  }
  return;
}

/* Loops over the unsorted vector of eigenvalues and sorts eigenvalues and
eigenvectors from smallest to largest eigenvalue */
vec sort_eigenpairs(mat &R, vec eigvals, int n) {
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
  vec eigvals_sorted = sort_eigenpairs(R, eigvals, n);
  return eigvals_sorted;
}
