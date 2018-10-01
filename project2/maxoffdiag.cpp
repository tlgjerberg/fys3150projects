#include "jacobi.h"

/* Finds the maximum off-diagonal element of matrix A and changes indices k, l
in memory */
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
