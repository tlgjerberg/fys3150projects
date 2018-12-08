#ifndef PDEsolvers_H
#define PDEsolvers_H

#include "tridiag_solver.hpp"
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
  ofstream outfile;
  void binarywrite(char *outfilename, int n);

public:
  vec u;
  vec r;
  Tridiag tridiag;

  // PDEsolvers();
  PDEsolvers(double bound1, double bound2, Tridiag tridiag);
  // ~PDEsolvers();
  void init_cond(double init1, int n);
  void Explicit_Euler(int n, int tsteps, double alpha);
  void Implicit_Euler(int n, int tsteps, double diag, double subdiag,
                      double superdiag);
  void Crank_Nicolson(int n, int tsteps, double alpha);
};

#endif /* PDEsolvers_H */
