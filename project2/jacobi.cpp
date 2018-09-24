#include <armadillo>
#include <cmath>
#include <iostream>
using namespace std;
using namespace arma;

// -DARMA_DONT_USE_WRAPPER -llapack -lblas

double maxoffdiag(mat A, int &k, int &l, int n) {
  double max = 0.0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      double a_ij = fabs(A(i, j));
      if (a_ij > max) {
        max = a_ij;
        k = i;
        l = j;
      }
    }
  }
  return max;
}

void rotation(mat &A, int &k, int &l, int n) {

  double c, s;
  double t, tau;

  if (A(k, l) != 0.0) {
    tau = (A(l, l) - A(k, k)) / (2 * A(k, l));
    double t1, t2;
    // t1 = -tau + sqrt(1 + tau * tau);
    // t2 = -tau - sqrt(1 + tau * tau);
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
  }
  return;
}

int main(int argc, char const *argv[]) {

  int n = atoi(argv[1]);
  double rho_N = 1;
  double rho_0 = 0;
  double h = (rho_N - rho_0) / n;
  double hh = h * h;

  mat A = zeros(n, n);
  A.diag() += 2 / hh;
  A.diag(1) += -1 / hh;
  A.diag(-1) += -1 / hh;

  cout << A << endl;

  vec eigval;
  mat eigvec;

  eig_sym(eigval, eigvec, A);

  cout << eigval << eigvec << endl;
  int k, l;
  double eps = 1e-8;
  double max = maxoffdiag(A, k, l, n);
  int max_iter = (double)n * (double)n * (double)n;
  int iter = 0;
  while (max > eps && iter < max_iter) {
    max = maxoffdiag(A, k, l, n);
    rotation(A, k, l, n);
    iter++;

    // cout << max << endl;
  }
  cout << "Number of iterations: " << iter << endl;
  cout << A << endl;
  return 0;
}
