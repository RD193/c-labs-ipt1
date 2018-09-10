#include <iostream>
#include <cmath>
int main() 
{
  std::cout << "vvedite a>=1";
  double a;
  std::cin >> a;
  double a_s = sin(a), a_1 = 1/a;
  if(a_s > a_1)
  {
    std::cout << "sin bigger";
  }
  else if(a_s < a_1)
  {
    std::cout << "1/ bigger";
  }
  else 
  {
    std::cout << "equal";
  }
  return 0;
}
