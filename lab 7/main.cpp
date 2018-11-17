#include <iostream>
#include "calc.h"
using namespace std;
int main() {
  try
  {
    cout << calc(1,-1);
  }
  catch(int code)
  {
    cout << "This block must do smt";
    if(code==1)
    {
      cout << "can't devide by zero";
    }
    else
    {
      cout <<"a must be positive. Negative given" << endl;
    }
  }
}