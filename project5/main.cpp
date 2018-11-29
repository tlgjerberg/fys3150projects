#include "PDEsolvers.hpp"
#include "tridiag_solver.hpp"

int main(int argc, char const *argv[]) {
  int n = argv[1];
  double h = argv[2];
  double hh = h * h;

  initialize(n, hh);
  // Gauss_Seidel();
  return 0;
}
