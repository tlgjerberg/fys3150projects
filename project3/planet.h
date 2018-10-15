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
  double x;
  double y;
  double z;
  double vx;
  double vy;
  double vz;
  double kinetic;
  double potential;

  planet();
  ~planet() {}
  planet(vec3 position, vec3 velocity, const double M);
  double distance(planet otherplanet);
  double GForce(planet otherplanet);
};

#endif // Planet_H
