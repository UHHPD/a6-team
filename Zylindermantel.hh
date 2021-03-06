#ifndef ZYLINDERMANTEL_HH
#define ZYLINDERMANTEL_HH
#include "Vektor.hh"
#include "Koerper.hh"

class Zylindermantel : public Koerper{
public:
  Zylindermantel(double nr, double nl);

  Vektor punkt();

  std::string name();

private:
  double r_, l_;
};

#endif
