#ifndef Solar_system_H
#define Solar_system_H

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
  double position[2];
  double velocity[2];
  double kinetic;
  double potential;

  planet();
  planet(double x, double y, double vx, double vy);
  double distance(planet otherplanet);
  double GForce(planet otherplanet);
};

#endif // Solar_system_H
