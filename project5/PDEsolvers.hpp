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

public:
  double *u;
  double *r;
  PDEsolvers(double bound1, double bound2);
  ~PDEsolvers();
  void init_cond(double init1, int n);
  void Explicit_Euler(int n, double *d, double *b, double *upper);
  void Implicit_Euler(int n, double *d, double *b, double *upper);
  void Crank_Nicolson();
};

#endif /* PDEsolvers_H */
