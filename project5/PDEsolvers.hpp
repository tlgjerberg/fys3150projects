#ifndef PDEsolvers_H
#define PDEsolvers_H

#include <armadillo>
#include <fstream>
#include <iostream>

using namespace arma;
using namespace std;

class PDEsolvers {

private:
  double u_0;
  double b_0;
  double b_L;

public:
  // double *u;
  // double *r;
  vec u;
  vec r;
  PDEsolvers(double bound1, double bound2);
  ~PDEsolvers();
  void init_cond(double init1, int n);
  void Explicit_Euler(int n, int tsteps, double alpha);
  void Implicit_Euler(int n, vec &d, vec &b, vec &upper);
  void Crank_Nicolson();
};

#endif /* PDEsolvers_H */
