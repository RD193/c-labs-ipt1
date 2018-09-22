#include <iostream>
#include <cmath>
using namespace std;
double y(int x, int a);

int main() {
  //cout << y(3,4);
  //cout << y(2,0);
}

double y(int x, int a)
{
  if(sin(a) == 0)
  {
    cout << "denominator = 0";
    throw "division by zero";
  }
  return cos(pow(x, 3)) + sqrt(x)/sin(a); 
}
