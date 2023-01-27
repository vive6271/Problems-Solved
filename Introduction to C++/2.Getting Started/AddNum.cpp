#include <iostream>
using namespace std;

int main() {
  int a = 10;
  int b = 15;
  int c = a + b;

  cout << c << endl;

  char d = 'X';

  cout << d << endl;

  float e = 1.25;

  cout << e << endl;

  double f = 1.2224;

  cout << f << endl;

  bool g = true;
  bool h = false;

  cout <<"true - "<<  g << " false-  " << h << endl;

  int size1 = sizeof(e);
  int size2 = sizeof(f);

  cout << "float - " << size1 << " double - " << size2 << endl;
}
