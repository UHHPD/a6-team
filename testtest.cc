#include <iostream>
#include <cmath>
#include "kreuz.hh"


using namespace std;


int main()
{
  int a,b;
std::cin>> a;
std::cin>> b;
  
  //constructer call ^_^
  kreuz k1(a, b);

  std::cout << "erste koord. " << k1.getX() << "\n" << "zweite koord. "<< k1.getY();

  return 0;

}