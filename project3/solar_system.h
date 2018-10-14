#ifndef Solar_system_H
#define Solar_system_H

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
  vec3 position();
  vec3 velocity;
  double kinetic;
  double potential;

  planet();
  planet(vec3 position, vec3 velocity);
  double distance(planet otherplanet);
  double GForce(planet otherplanet);
};

#endif // Solar_system_H
