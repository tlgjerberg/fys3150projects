#include "planet.h"
#include "solver.h"
#include "vec3.h"

planet::planet() {
  x = 1.;
  y = 1.;
  z = 1.;
  vx = 1.;
  vy = 1.;
  vz = 1.;
  kinetic = 1.;
  potential = 1.;
}

planet::planet(vec3 position, vec3 velocity, const double M) {
  x = position[0];
  y = position[1];
  z = position[2];
  vx = velocity[0];
  vy = velocity[1];
  vz = velocity[2];
  mass = M;
}

double planet::distance(planet otherplanet) {
  x = x - otherplanet.x;
  y = y - otherplanet.y;
  z = z - otherplanet.z;
  return sqrt(x * x + y * y + z * z);
}

vec3 planet::GForce(planet otherplanet) {
  double M1, M2, r;
  M1 = mass;
  M2 = otherplanet.mass;
  r = distance(otherplanet);
  gforce[0] = -G * (M2 * M1 / pow(r, 3)) * x;
  gforce[1] = -G * (M2 * M1 / pow(r, 3)) * y;
  gforce[2] = -G * (M2 * M1 / pow(r, 3)) * z;
  return gforce;
}

vec3 planet::accel(planet otherplanet, vec3 gforce) {
  vec3 acceleration;
  acceleration = gforce / mass;
  return acceleration;
}
