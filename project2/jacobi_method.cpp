#include "jacobi.h"

vec jacobi_method(mat A, double eps, double max, int k, int l, int n) {
  int max_iter = (double)n * (double)n * (double)n;
  int iter = 0;
  while (max > eps && iter < max_iter) {
    max = maxoffdiag(A, k, l, n);
    rotation(A, k, l, n);
    iter++;
  }
  cout << "Number of iterations: " << iter << endl;
  return diagvec(A);
}