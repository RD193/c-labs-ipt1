#include <iostream>

int main() {
  int a, b, c, res;
  std::cin >> a >> b >> c;
  res = a;
  if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0)
  {
    if (b > res) {res = b;} // не буду писать цикл ради 2-х штук
    if (c > res) {res = c;} // равно как и пробелы ставить
  }
  else
  {
    std::cout << res;
    if (b < res) {res = b;} // не буду писать цикл ради 2-х штук
    if (c < res) {res = c;} // равно как и пробелы ставить
  }
  std::cout << "resoult " << res;
  return 0;
}
