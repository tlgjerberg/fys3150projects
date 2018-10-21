#ifndef Solver_H
#define Solver_H
#define _USE_MATH_DEFINES
// #define ARMA_64BIT_WORD

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
public:
  friend class planet;
  friend class SolarSystem;
  SolarSystem *solsys;
  double x, y, z;
  double vx, vy, vz;
  double pi = M_PI;
  double G = 4 * pi * pi;
  // mat position, velocity;
  double radius;

  solver();
  solver(double r);
  void euler(planet &current, planet &other, int n, double h);
  void verlet(SolarSystem &solsys, int n, double h);
};

#endif // Solver_H
