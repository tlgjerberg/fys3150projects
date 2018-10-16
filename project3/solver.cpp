#include "planet.h"
#include "solar_system.h"
#include "solver.h"
#define _USE_MATH_DEFINES

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
    if (i % 10 == 0) {
      ofile << x << " " << y << endl;
    }
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
  double tmpax, tmpay, tmpaz;
  double hh = h * h;
  ofstream ofile;
  double ax, ay, az;
  char *sol_array;

  ofile.open("sol_array.txt");
  for (int i = 0; i < n; i++) {
    double r = current.distance(other);
    // vec3 a = current.accel(other);
    tmpax = -4 * (pi * pi * x) / pow(r, 3);
    tmpay = -4 * (pi * pi * y) / pow(r, 3);
    tmpaz = -4 * (pi * pi * z) / pow(r, 3);
    x = x + h * vx + (hh / 2) * tmpax;
    y = y + h * vy + (hh / 2) * tmpay;
    z = z + h * vz + (hh / 2) * tmpaz;
    // cout << tmpax << endl;
    // a = current.accel(other);
    ax = -4 * (pi * pi * x) / pow(r, 3);
    ay = -4 * (pi * pi * y) / pow(r, 3);
    az = -4 * (pi * pi * z) / pow(r, 3);
    // cout << ax << ay << endl;
    vx = vx + (h / 2) * (ax + tmpax);
    vy = vy + (h / 2) * (ay + tmpay);
    vz = vz + (h / 2) * (az + tmpaz);
    if (i % 10 == 0) {
      ofile << x << " " << y << endl;
    }
  }

  ofile.close();
  return;
}
