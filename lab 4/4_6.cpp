#include <iostream>
using namespace std;
int *join(int q[], int r[]);
int main() {
  cout << "print length";
  int n;//мне лень придумывать нормальные названия а потом печатать их каждый раз
  int *c = new int[1];
  cin >> n;
  int a[n], b[n];
  for(int i = 0; i < n*2; i = i + 2)
  {
    c[i] = 1;
    c[i+1] = 2;
  }
  for(int i = 0; i < n*2; i++)
  {
    cout << c[i] << "    ";
  }
  cout << "\n";
  int *r = join(a,b);
  for(int i = 0; i < n*2; i++)
  {
    cout << r[i] << "    ";
  }

  delete [] c;

}
int *join(int *q, int *r) // Вне зависимости от динны и без всяких там динамических 
{                         //массивов, жаль что не работает
  const int size = sizeof(q);
  static int resoult[size];
  for(int i = 0; i < size; i = i + 2)
  {
    resoult[i] = 1;
    resoult[i+1] = 2;
  } 
  return resoult;
}
