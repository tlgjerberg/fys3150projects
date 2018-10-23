#include "planet.h"
#include "solar_system.h"
#include "solver.h"
// #include "vec3.h"

int main(int argc, char const *argv[]) {
  double t = 12.0;
  int n = 10000;
  int N = n * t;
  double h = t / N;
  double days = 365;
  SolarSystem solsys;
  vec pos_ea = {8.762968100249854E-01, 4.788339338174544E-01,
                -9.307050339169484E-05};
  vec vel_ea = {-8.439075390315470E-03 * 365, 1.508194738302731E-02 * 365,
                -1.191747734059677E-07 * 365};
  vec pos_sun = {-2.082456923795519E-04, 7.269365845327120E-03,
                 -7.116216262733176E-05};
  vec vel_sun = {-7.605663822232906E-06 * 365, 2.520655405552306E-06 * 365,
                 1.901417766099408E-07 * 365};
  vec pos_ju = {-2.608627805978873E+00, -4.685828309297189E+00,
                7.778573346168467E-02};
  vec vel_ju = {6.502462708302700E-03 * 365, -3.310060301323844E-03 * 365,
                -1.317114883681856E-04 * 365};

  vec pos_mer = {2.268331723540750E-02, -4.527628626217761E-01,
                 -3.976201975514675E-02};

  vec vel_mer = {2.244877340585597E-02 * 365, 2.845538482588606E-03 * 365,
                 -1.827605072960171E-03 * 365};
  vec pos_mars = {1.715983489669008E+01, 1.002337888498547E+01,
                  -1.850808899423016E-01};
  vec vel_mars = {-2.012564320999376E-03 * 365, 3.212817188979134E-03 * 365,
                  3.794752627046652E-05 * 365};

  vec pos_ven = {6.530757128601843E-01, 3.190875185361919E-01,
                 -3.349172978023899E-02};
  vec vel_ven = {-8.785579830448000E-03 * 365, 1.816800217747395E-02 * 365,
                 7.559643446621499E-04 * 365};

  vec pos_sat = {1.590783136382971E+00, -9.928373213347987E+00,
                 1.093066740224694E-0};

  vec vel_sat = {5.202029044650378E-03 * 365, 8.643867158422751E-04 * 365,
                 -2.218987750237153E-04};
  vec pos_ur = {1.715983489669008E+01, 1.002337888498547E+01,
                -1.850808899423016E-01};
  vec vel_ur = {-2.012564320999376E-03 * 365, 3.212817188979134E-03 * 365,
                3.794752627046652E-05 * 365};
  vec pos_nep = {2.892660189793705E+01, -7.698124384621846E+00,
                 -5.081142758387712E-01};
  vec vel_nep = {7.867629584697290E-04 * 365, 3.052058598329926E-03 * 365,
                 -8.137189860419682E-05 * 365};

  planet earth(pos_ea, vel_ea, 0.000003);
  planet sun(pos_sun, vel_sun, 1);
  planet jupiter(pos_ju, vel_ju, 0.00095);
  planet mercury(pos_mer, vel_mer, 1.65e-7);
  planet venus(pos_ven, vel_ven, 2.45e-6);
  planet mars(pos_mars, vel_mars, 3.3e-7);
  planet saturn(pos_sat, vel_sat, 2.75e-4);
  planet uranus(pos_ur, vel_ur, 4.4e-5);
  planet neptune(pos_nep, vel_nep, 5.15e-5);

  solsys.add_celestial_objects(sun);
  solsys.add_celestial_objects(mercury);
  solsys.add_celestial_objects(venus);
  solsys.add_celestial_objects(earth);
  solsys.add_celestial_objects(mars);
  solsys.add_celestial_objects(jupiter);
  solsys.add_celestial_objects(saturn);
  solsys.add_celestial_objects(uranus);
  solsys.add_celestial_objects(neptune);

  solver solar;
  solar.verlet(solsys, N, h);
  // binobj.euler(planet1, planet2, N, h);
  return 0;
}
