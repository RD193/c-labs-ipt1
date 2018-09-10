#include <iostream>

int main() {
  float a, b;
  std::cin >> a >> b;
  a = (a + b) / 2;
  b = (2 * a - b * 2) / 2;
  std::cout << a <<"  " << b;
}