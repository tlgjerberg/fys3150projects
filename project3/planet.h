#ifndef Planet_H
#define Planet_H

// #include "vec3.h"
// #include "solar_system.h"
// #include "solver.h"
#include <armadillo>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

#define _USE_MATH_DEFINES

using std::vector;
using namespace std;
using namespace arma;

class planet {
private:
  double G = 4 * pow(M_PI, 2);

public:
  double mass;
  vec position;
  vec velocity;
  double x, y, z;
  double vx, vy, vz;
  double ax, ay, az;
  vec gforce;
  double pi = M_PI;

  planet();
  ~planet() {}
  planet(vec position, vec velocity, const double M);
  double distance(planet otherplanet);
  vec GForce(planet otherplanet);
  vec accel(planet otherplanet);
  // double kinetic();
  // double potential(planet otherplanet);
};

#endif // Planet_H
