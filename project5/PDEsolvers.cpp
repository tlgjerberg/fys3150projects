#include "PDEsolvers.hpp"
#include "tridiag_solver.hpp"

// PDEsolvers::PDEsolvers() {}

PDEsolvers::PDEsolvers(double bound1, double bound2, Tridiag tridiag) {
  double b_0 = bound1;
  double b_L = bound2;
  this->tridiag = tridiag;
  // int n;
}

// PDEsolvers::~PDEsolvers() {
//   // delete[] u;
//   // delete[] d;
// }

// Defines initial conditions for a PDE with first order time derivative
void PDEsolvers::init_cond(double init1, int n) {
  u = zeros(n);
  u.fill(init1);
}

// Explicit Euler algorithm
void PDEsolvers::Explicit_Euler(int n, int tsteps, double alpha) {
  // char *outfilename = "Ex_euler.dat";
  u(0) = b_0;
  u(n - 1) = b_L;
  for (int l = 1; l < tsteps; l++) {
    for (int i = 1; i < n - 1; i++) {
      u(i) = (1.0 - 2.0 * alpha) * u(i) + alpha * u(i + 1) + alpha * u(i - 1);
    }
    u(0) = b_0;
    u(n - 2) = b_L;
  }
  // binarywrite(outfilename);
  return;
}

void PDEsolvers::Implicit_Euler(int n, int tsteps, double diag, double subdiag,
                                double superdiag) {
  for (int l = 1; l < tsteps; l++) {
    tridiag.Gauss();
  }
  return;
}

void PDEsolvers::Crank_Nicolson(int n, int tsteps, double alpha) {
  r = zeros(n);
  for (int l = 1; l < tsteps; l++) {
    for (int i = 1; i < n - 1; i++) {
      r(i) = alpha * u(i - 1) + (2.0 - 2.0 * alpha) * u(i) + alpha * u(i + 1);
    }
    r(0) = 0.0;
    r(n - 1) = 1.0;
    tridiag.Gauss_Seidel(r);
    // preserving boundary conditions
    u(0) = 0.0;
    u(n - 1) = 1.0;

    r = u;
  }
}

void PDEsolvers::binarywrite(char *outfilename) {
  typedef std::vector<double> stdvec;
  stdvec x = conv_to<stdvec>::from(r);
  outfile.open(outfilename, ios::binary);
  outfile.write((char *)&x[0], x.size() * sizeof(double));
  // outfile.write(reinterpret_cast<char *>(x), n * sizeof(double));
  outfile.close();
}
