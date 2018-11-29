#ifndef PDEsolvers_H
#define PDEsolvers_H

#include <armadillo>
#include <fstream>
#include <iostream>

class PDEsolvers {

private:
  double u_0;
  double u_n;
  double b_0;
  double b_L;

public:
  PDEsolvers PDEsolvers(double init1, double init2, double bound1,
                        double bound2);
  void Explicit_Euler();
  void Implicit_Euler();
  void Crank_Nicolson();
};

// Main for testing
int main(int argc, char const *argv[]) { return 0; }

#endif /* PDEsolvers_H */
