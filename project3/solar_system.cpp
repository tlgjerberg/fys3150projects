#include "planet.h"
#include "solar_system.h"
#include "solver.h"

SolarSystem::SolarSystem() {}
int SolarSystem::length() { return celestial_objects.size(); }

mat SolarSystem::accel() {
  int n = celestial_objects.size();
  mat A = zeros(3, n);
  for (int i = 0; i < n; i++) {
    vec accel = celestial_objects[i].accel(celestial_objects[i + 1]);

    for (int j = i + 1; j < n; j++) {
      A(0, j) += accel(0);
      A(1, j) += accel(1);
      A(2, j) += accel(2);
    }
  }
  return A;
}
