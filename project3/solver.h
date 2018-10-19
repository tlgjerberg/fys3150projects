#ifndef Solver_H
#define Solver_H
#define _USE_MATH_DEFINES

#include "planet.h"
#include "solar_system.h"
// #include "vec3.h"
#include <armadillo>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

using std::vector;
using namespace std;

class solver {
private:
  double x;
  double y;
  double z;
  double vx;
  double vy;
  double vz;
  double pi = M_PI;
  double G = 4 * pi * pi;

public:
  friend class planet;
  friend class SolarSystem;
  double radius;

  solver();
  solver(double r);
  void euler(planet &current, planet &other, int n, double h);
  void verlet(SolarSystem solsys, int n, double h);
};

#endif // Solver_H
