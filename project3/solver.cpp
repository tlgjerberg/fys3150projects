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

void solver::verlet(SolarSystem solsys, int n, double h) {
  // x = current.x;
  // y = current.y;
  // z = current.z;
  // vx = current.vx;
  // vy = current.vy;
  // vz = current.vz;
  mat position = solsys.position();
  mat velocity = solsys.velocity();
  double tmpax, tmpay, tmpaz;
  double hh = h * h;
  ofstream ofile;
  // double ax, ay, az;
  mat preva;
  mat a;
  char *sol_array;

  ofile.open("sol_array.txt");
  for (int i = 0; i < n; i++) {

    preva = solsys.accel();
    // cout << preva << endl;
    position += h * velocity + (hh / 2) * preva;
    cout << position << endl;
    // tmpay = -4 * (pi * pi * y) / pow(r, 3);
    // tmpaz = -4 * (pi * pi * z) / pow(r, 3);
    // pos += h * vel + (hh / 2) * preva;
    // y += h * vy + (hh / 2) * tmpay;
    // z += h * vz + (hh / 2) * tmpaz;
    a = solsys.accel();
    // cout << a << endl;
    // ay = -4 * (pi * pi * y) / pow(r, 3);
    // az = -4 * (pi * pi * z) / pow(r, 3);
    velocity += (h / 2) * (a + preva);
    // vx += (h / 2) * (ax + tmpax);
    // vy += (h / 2) * (ay + tmpay);
    // vz += (h / 2) * (az + tmpaz);
    if (i % 10 == 0) {
      ofile << position(0, 0) << " " << position(1, 0) << endl;
    }
  }

  ofile.close();
  return;
}
