#include "solar_system.h"
#include "solver.h"

solver::solver() { radius = 1.0; }

solver::solver(double r) { radius = r; }

void solver::euler(planet &current, planet &other, int n, double h) {
  x = current.x;
  y = current.y;
  z = current.z;
  vx = current.vx;
  vy = current.vy;
  vz = current.vz;
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

void solver::verlet(planet &current, planet &other, int n, double h) {
  x = current.x;
  y = current.y;
  z = current.z;
  vx = current.vx;
  vy = current.vy;
  vz = current.vz;
  double ax;
  double ay;
  double az;
  double hh = h * h;
  ofstream ofile;

  char *sol_array;

  ofile.open("sol_array.txt");
  for (int i = 0; i < n; i++) {
    double r = current.distance(other);
    x = x + h * vx + (hh / 2) * ax;
    y = y + h * vy + (hh / 2) * ay;
    ay = -(G * current.mass / pow(r, 3)) * y;
    ax = -(G * current.mass / pow(r, 3)) * x;
    vx = vx + (h / 2) * (ax + ax);
    vy = vy + (h / 2) * (ay + ay);
    ofile << x << " " << y << endl;
  }

  ofile.close();
  return;
}

// double **CreateMatrix(int row, int col) {
//   double **M;
//   M = new double *[row];
//   for (int i = 0; i < row; i++) {
//     M[i] = new double[col];
//   }
// }
// return (double **)M;
// }
