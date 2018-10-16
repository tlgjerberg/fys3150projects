#ifndef Planet_H
#define Planet_H

#include "vec3.h"
// #include <armadillo>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

#define _USE_MATH_DEFINES

using std::vector;
using namespace std;

class planet {
private:
  double G = 4 * pow(M_PI, 2);

public:
  double mass;
  vec3 position;
  vec3 velocity;
  double x, y, z;
  double vx, vy, vz;
  double ax, ay, az;
  vec3 gforce;
  double pi = M_PI;

  planet();
  ~planet() {}
  planet(vec3 position, vec3 velocity, const double M);
  double distance(planet otherplanet);
  vec3 GForce(planet otherplanet);
  vec3 accel(planet otherplanet);
  // double kinetic();
  // double potential(planet otherplanet);
};

#endif // Planet_H
