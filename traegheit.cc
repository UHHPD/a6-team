#include "Vektor.hh"
#include "Zylindermantel.hh"
#include "Vollzylinder.hh"
#include <iostream>
#include <memory>

using namespace std;

int main() {
  const int N = 1e4;     // Anzahl Integrationspunkte
  double M = 1.0;      // Masse des Zylindermantels
  double ZM_R = 1.0; // Radius der Zylindermantels
  double ZM_L = 1.0; // Laenge des Zylindermantels
  cout << "Masse: \n";
  cin >> M;
  cout << "Radius: \n";
  cin >> ZM_R;
  cout << "Länge:\n";
  cin >> ZM_L;


  Vektor a(0,ZM_R,0);
  Vektor u(0,0,1);

  unique_ptr<Zylindermantel> zm(new Zylindermantel(ZM_R, ZM_L));

  double J = 0;     // Massentraegheitsmoment
  double m = M / N; // Masse eines Massenpunktes
  for (int i = 0; i < N; i++) {
    Vektor x = zm->punkt();
    
    Vektor n = (x-a).kreuz(u);
    double r = n.betrag() / u.betrag();
    
    J += m * r * r;
  }
  std::cout << "Massentraegheitsmoment fuer einen Zylindermantel"
            << " mit a = " << a << " und u = " << u << ": " << J << std::endl;



  unique_ptr<Vollzylinder> vz(new Vollzylinder(ZM_R, ZM_L));

  J = 0;     // Massentraegheitsmoment
  m = M / N; // Masse eines Massenpunktes
  for (int i = 0; i < N; i++) {
    Vektor x = vz->punkt();
    
    Vektor n = (x-a).kreuz(u);
    double r = n.betrag() / u.betrag();
    
    J += m * r * r;
  }
  std::cout << "Massentraegheitsmoment fuer einen Vollzylinder"
            << " mit a = " << a << " und u = " << u << ": " << J << std::endl;
  
  
  return 0;
}
