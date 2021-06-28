#include "Vektor.hh"
#include "Koerper.hh"
#include "Zylindermantel.hh"
#include "Vollzylinder.hh"
#include <iostream>
#include <memory>

using namespace std;

const int N = 1e4;     // Anzahl Integrationspunkte
double M = 1.0;      // Masse des Zylindermantels
double ZM_R = 1.0; // Radius der Zylindermantels
double ZM_L = 1.0; // Laenge des Zylindermantels

double traegheit (Koerper* k , Vektor a, Vektor u) {
  cout << "berechne für " << k-> name() << "\n";

  double J = 0;     // Massentraegheitsmoment
  double m = M / N; // Masse eines Massenpunktes
  for (int i = 0; i < N; i++) {
    Vektor x = k->punkt();
    
    Vektor n = (x-a).kreuz(u);
    double r = n.betrag() / u.betrag();
    
    J += m * r * r;
  }
  std::cout << "Massentraegheitsmoment fuer einen " << k-> name() 
            << " mit a = " << a << " und u = " << u << ": " << J << endl;

}

int main() {
  cout << "Masse: \n";
  cin >> M;
  cout << "Radius: \n";
  cin >> ZM_R;
  cout << "Länge:\n";
  cin >> ZM_L;

  Vektor a(0,0,0);
  Vektor u(0,0,1);

  unique_ptr<Koerper> k1(new Zylindermantel(ZM_R, ZM_L));
  unique_ptr<Koerper> k2(new Vollzylinder(ZM_R, ZM_L));

  traegheit(k1.get(), a, u);
  traegheit(k2.get(), a, u);

  return 0;
}
