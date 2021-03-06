#include "Vollzylinder.hh"

#include <cmath>
#include <cstdlib>

using namespace std;

Vollzylinder::Vollzylinder(double nr, double nl) {
  r_ = nr;
  l_ = nl;
}

Vektor Vollzylinder::punkt() {
  double R = sqrt(1 * rand()/(double)RAND_MAX) * r_;
  double phi = 2 * M_PI * rand() / (double)RAND_MAX;
  double z = l_ * (rand() / (double)RAND_MAX - 0.5);

  double x = R * cos(phi);
  double y = R * sin(phi);
  return Vektor(x, y, z);
};

string Vollzylinder::name() {
  return "Vollzylinder";
}