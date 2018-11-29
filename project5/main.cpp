#include "PDEsolvers.hpp"
#include "tridiag_solver.hpp"

int main(int argc, char const *argv[]) {
  int n = atoi(argv[1]);
  double h = atof(argv[2]);
  double hh = h * h;

  Tridiag tridiag = Tridiag(2, -1, -1);

  tridiag.initialize(n, hh);
  // Gauss_Seidel();
  return 0;
}
