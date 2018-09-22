#include <iostream>

int main() {
  int number;
  std::cin >> number;
  if(number<0)
  {
    number*=-1;
    std::cout << number;
  }
  else
  {
    std::cout << number;
  }
}
