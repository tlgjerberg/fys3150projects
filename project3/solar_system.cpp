#include "solar_system.h"

planet::planet() {
  position[0] = 1.;
  position[1] = 1.;
  velocity[0] = 1.;
  velocity[1] = 1.;
  kinetic = 1.;
  potential = 1.;
}

planet::planet(double x, double y, double vx, double vy, double K, double V) {
  position[0] = x;
  position[1] = y;
  velocity[0] = vx;
  velocity[1] = vy;
  kinetic = K;
  potential = V;
}

double planet::distance(planet otherplanet) {
  double x, y;
  x = position[0] - otherplanet.position[0];
  y = position[1] - otherplanet.position[1];
  return sqrt(x * x + y * y);
}

double planet::GForce(planet otherplanet) {
  double M1, M2, r;
  M1 = mass;
  M2 = otherplanet.mass;
  r = distance(otherplanet);

  return -((G * M1 * M2) / r * r);
}
