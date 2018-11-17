#include <cmath> 
#include <string>
#include <iostream>
using namespace std;
float calc(int x, int a)
{
  if(a==0)
  {
    throw 1;
  }
  if(a < 0)
  {
    throw 2;
  } 
  return x*x*x + 1/(sqrt(a));
}