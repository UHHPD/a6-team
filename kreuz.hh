#include <iostream>

using namespace std;

class kreuz
    {

    private:
      int x, y;

    public:

      //constructer :)
      kreuz(int x1, int y1)
      {
        x = x1;
        y = y1;
      }
      int getX(){
        return x;
      }
      int getY(){
        return y;
      }
    };
