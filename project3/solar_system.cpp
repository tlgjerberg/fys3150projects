#include "planet.h"
#include "solar_system.h"
// #include "solver.h"

/*Initializes the SolarSystem with an empty declaration of a vector
with template planet which is an object from the planet class*/
SolarSystem::SolarSystem() { vector<planet> celestial_objects; }

/*Initializes the SolarSystem with a vector
with template planet which is an object from the planet class*/
SolarSystem::SolarSystem(vector<planet> init_cel_obj) {
  celestial_objects = init_cel_obj;
}

// Appends a planet object to the vector of planets celestial_objects
void SolarSystem::add_celestial_objects(planet planet) {
  celestial_objects.push_back(planet);
}
int SolarSystem::length() { return celestial_objects.size(); }

/*Method calculating the acceleration on one object from every other object
in the celestial_objects vector. Too save some steps the negative value */
mat SolarSystem::accel() {
  int n = celestial_objects.size(); // Number of planet-like objects
  // cout << "n:" << n << endl;
  vec drvec;
  double r;
  mat A = zeros(3, n); // Declaring matrix of zeros to store acceleration
  for (int i = 0; i < n; i++) {

    for (int j = i + 1; j < n; j++) {
      /* Difference in position between the current planet object and the next
        planet object*/
      drvec = celestial_objects[i].position - celestial_objects[j].position;
      // Distance between the current planet object with another other planet
      // object
      r = celestial_objects[i].distance(celestial_objects[j]);

      // Acceleration on the current object from the next objects
      A.col(i) += -G * celestial_objects[j].mass * (drvec) / pow(r, 3);
      // Acceleration for the next object from the current
      A.col(j) -= -G * celestial_objects[i].mass * (drvec) / pow(r, 3);
    }
  }
  return A;
}
/*Method for returning the referance to a vector containing the planets
in the Solar System object*/
vector<planet> &SolarSystem::objects() { return celestial_objects; }
