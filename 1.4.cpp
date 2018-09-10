#include <iostream>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  if( a >= b && b >= c)
  {
    a *=2;
    b*= 2;
    c *= 2;
  }
  else
  {
    a = a ^ b; //побитовые операции. помоему это самый производительный способ поменять
    b = a ^ b; //местами 2 числа
    a = a ^ b;
  }
  std::cout << a <<"    " << b << "    " << c;
}