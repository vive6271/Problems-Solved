#include<iostream>
using namespace std;

int main() {
  int a[10];
  int *p = &a[0];

  cout << a << endl;
  cout << p << endl;

  cout << &a << endl;
  cout << &p << endl;

  cout << sizeof(a) << endl;
  cout << sizeof(p) << endl;
  return 0;
}
