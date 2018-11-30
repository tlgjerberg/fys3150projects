#include "PDEsolvers.hpp"
#include "tridiag_solver.hpp"

int main(int argc, char const *argv[]) {
  int n = atoi(argv[1]);
  double h = atof(argv[2]);
  double hh = h * h;

  Tridiag tridiag = Tridiag(2, -1, -1);

  tridiag.initialize(n, hh);

  tridiag.Gauss_Seidel(n);

  PDEsolvers pde = PDEsolvers(0, 1);

  pde.init_cond(0, n);

  pde.Explicit_Euler(n, tridiag.d, tridiag.b, tridiag.upper);

  return 0;
}
