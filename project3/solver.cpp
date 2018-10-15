#include "planet.h"
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
    vx += -h * (4 * pow(M_PI, 2) / pow(r, 3)) * x;
    vy += -h * (4 * pow(M_PI, 2) / pow(r, 3)) * y;
    vz += -h * (4 * pow(M_PI, 2) / pow(r, 3)) * z;
    x += h * vx;
    y += h * vy;
    z += h * vz;
    ofile << x << " " << y << endl;
  }
  ofile.close();
  return;
}

void solver::verlet(planet &current, planet &other, int n, double h,
                    vec3 gforce) {
  x = current.x;
  y = current.y;
  z = current.z;
  vx = current.vx;
  vy = current.vy;
  vz = current.vz;
  double ax, ay, az;
  double tmpax, tmpay, tmpaz;
  double hh = h * h;
  ofstream ofile;

  char *sol_array;

  ofile.open("sol_array.txt");
  for (int i = 0; i < n; i++) {
    double r = current.distance(other);
    vec3 a = current.accel(other, gforce);

    x = x + h * vx + (hh / 2) * a[0];
    y = y + h * vy + (hh / 2) * a[1];
    z = z + h * vz + (hh / 2) * a[2];
    tmpax = a[0];
    tmpay = a[1];
    tmpaz = a[2];
    a = current.accel(other, gforce);
    vx = vx + (h / 2) * (a[0] + tmpax);
    vy = vy + (h / 2) * (a[1] + tmpay);
    vz = vz + (h / 2) * (a[2] + tmpaz);
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
