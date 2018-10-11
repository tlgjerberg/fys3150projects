#define _USE_MATH_DEFINES
#include "solver.h"

void euler(double *x, double *y, double *vx, double *vy, int n, double h,
           double MS, double G) {
  x[0] = 1.0;
  y[0] = 0.0;
  vx[0] = 0.0;
  vy[0] = 2.0 * M_PI;
  for (int i = 0; i < n; i++) {
    double r = sqrt(pow(x[i], 2) + pow(y[i], 2));
    vx[i + 1] = vx[i] - h * (4 * pow(M_PI, 2) / pow(r, 3)) * x[i];
    x[i + 1] = x[i] + h * vx[i];
    vy[i + 1] = vy[i] - h * (4 * pow(M_PI, 2) / pow(r, 3)) * y[i];
    y[i + 1] = y[i] + h * vy[i];

    ofstream ofile;

    char *sol_array;

    ofile.open("sol_array.txt");

    for (int i = 1; i < n; i++) {
      ofile << x[i] << " " << y[i] << endl;
    }

    ofile.close();
  }

  return;
}

void verlet(double *x, double *y, double *vx, double *vy, int n, double h,
            double MS, double G) {
  x[0] = 1.0;
  y[0] = 0.0;
  vx[0] = 0.0;
  vy[0] = 2.0 * M_PI;
  double *ax = new double[n];
  double *ay = new double[n];
  double hh = h * h;
  for (int i = 0; i < n; i++) {
    double r = sqrt(pow(x[i], 2) + pow(y[i], 2));
    x[i + 1] = x[i] + h * vx[i] + (hh / 2) * ax[i];
    y[i + 1] = y[i] + h * vy[i] + (hh / 2) * ay[i];
    ay[i + 1] = -(G * MS / pow(r, 3)) * y[i];
    ax[i + 1] = -(G * MS / pow(r, 3)) * x[i];
    vx[i + 1] = vx[i] + (h / 2) * (ax[i + 1] + ax[i]);
    vy[i + 1] = vy[i] + (h / 2) * (ay[i + 1] + ay[i]);
  }
  ofstream ofile;

  char *sol_array;

  ofile.open("sol_array.txt");

  for (int i = 1; i < n; i++) {
    ofile << x[i] << " " << y[i] << endl;
  }

  ofile.close();
  return;
}

// int main(int argc, char const *argv[]) {
//   int n = 1000;
//   double h = 0.01;
//   double MS = 2e30;
//   double ME = 6e24;
//   double G = 6.67e-11;
//   double *x = new double[n];
//   double *y = new double[n];
//   double *vx = new double[n];
//   double *vy = new double[n];
//   // euler(x, y, vx, vy, n, h, MS, G);
//   verlet(x, y, vx, vy, n, h, MS, G);
//   return 0;
// }
