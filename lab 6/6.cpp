#include <iostream>
#include <string>
#include <cmath>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main() {
  srand(time(NULL));
  string leters = "abcdefghijklmnopqrstqvwxyz";
  int num = rand() % 25;
  int len = 25;
  int len2 = 25;
  while(true)
  {
    char leter;
    cin >> leter;
    int pos = leters.find(leter);
    if(pos == num)
    {
      cout << "win";
      break;
    }
    else
    {
      len2 = abs(num - pos);
    }
    if(len2 < len)
    {
      cout << "Hoter";
    }
    else
    {
      cout << "Colder";
    }
    len = len2;   
  }
}
