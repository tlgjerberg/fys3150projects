#ifndef PDEsolvers_H
#define PDEsolvers_H

#include <armadillo>
#include <fstream>
#include <iostream>

class PDEsolvers {

private:
  double u_0;
  double b_0;
  double b_L;
  double *u;

public:
  PDEsolvers(double init1, double bound1, double bound2);
  void Explicit_Euler(int n);
  void Implicit_Euler();
  void Crank_Nicolson();
};

#endif /* PDEsolvers_H */
