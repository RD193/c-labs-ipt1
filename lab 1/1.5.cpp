#include <iostream>
#include <math.h>
int main() {
  int r;
  double x, y;
  std::cin >> r >> x >> y;
  if(r / 2 * sqrt(2) == sqrt(x*x + y * y))
  {
    std::cout << "True";
  }
  else
  {
    float a = r / 2 * sqrt(2), b = sqrt(x*x + y * y);
    std::cout << " False" << a << "        "<< b;
  }
}
