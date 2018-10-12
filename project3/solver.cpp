#include "solar_system.h"
#include "solver.h"

solver::solver() { radius = 1.0; }

solver::solver(double r) { radius = r; }

void solver::euler(planet &current, planet &other, int n, double h) {
  double x = current.position[0];
  double y = current.position[1];
  double vx = current.velocity[0];
  double vy = current.velocity[1];
  ofstream ofile;

  char *sol_array;

  ofile.open("sol_array.txt");
  for (int i = 0; i < n; i++) {
    double r = current.distance(other);
    vx += vx - h * (4 * pow(M_PI, 2) / pow(r, 3)) * x;
    x += x + h * vx;
    vy += vy - h * (4 * pow(M_PI, 2) / pow(r, 3)) * y;
    y += y + h * vy;

    ofile << x << " " << y << endl;
  }
  ofile.close();
  return;
}

/*

void solver::verlet(double *x, double *y, double *vx, double *vy, int n,
                    double h, double MS, double G) {
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

double **CreateMatrix(int row, int col) {
  double **M;
  M = new double *[row];
  for (int i = 0; i < row; i++) {
    M[i] = new double[col];
  }
}
return (double **)M;
}


*/
