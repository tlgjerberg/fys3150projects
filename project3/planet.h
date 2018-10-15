#ifndef Planet_H
#define Planet_H

#include "vec3.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

using std::vector;
using namespace std;

class planet {
private:
  double G = 6.67e-11;

public:
  double mass;
  vec3 position;
  vec3 velocity;
  double x, y, z;
  double vx, vy, vz;
  double ax, ay, az;
  vec3 gforce;
  double kinetic;
  double potential;

  planet();
  ~planet() {}
  planet(vec3 position, vec3 velocity, const double M);
  double distance(planet otherplanet);
  vec3 GForce(planet otherplanet);
  vec3 accel(planet otherplanet, vec3 gforce);
};

#endif // Planet_H
