#include <iostream>
#include <cmath>
using namespace std;
int main() {
  int arc, func;
  cin >> func;
  cin >> arc;
  switch(func)
  {
    case 1:{ cout << sin(arc); break;}
    case 2:{ cout << cos(arc); break;}
    case 3:{ cout << tan(arc); break;}
    default:{ cout << "ne ta cifra"; break;}
  }
}
