#ifndef PDEsolvers_H
#define PDEsolvers_H

#include <armadillo>
#include <fstream>
#include <iostream>

class PDEsolvers {

private:
public:
  Explicit_Euler();
  Implicit_Euler();
  Crank_Nicolson();
};

// Main for testing
int main(int argc, char const *argv[]) { return 0; }

#endif /* PDEsolvers_H */
