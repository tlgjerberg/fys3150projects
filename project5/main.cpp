#include "PDEsolvers.hpp"
#include "tridiag_solver.hpp"

int main(int argc, char const *argv[]) {
  int n = atoi(argv[1]);
  int tsteps = atoi(argv[2]);
  double h = atof(argv[3]);
  double ht = atof(argv[4]);
  double hh = h * h;
  double alpha = ht / hh;

  Tridiag tridiag = Tridiag(2, -1, -1);

  tridiag.initialize(n);

  PDEsolvers pde = PDEsolvers(0, 1, tridiag);

  pde.init_cond(0, n);

  pde.Explicit_Euler(n, tsteps, alpha);

  // pde.Implicit_Euler()

  pde.Crank_Nicolson(n, tsteps, alpha);

  return 0;
}
