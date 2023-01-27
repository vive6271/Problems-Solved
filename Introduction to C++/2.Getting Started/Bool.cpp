#include <iostream>
using namespace std;

int main() {
  int a;
  int b;
  cout << "Enter Value of A and B" << endl;
  cin >> a >> b;

  bool isEqual = (a == b);
  bool isGreater = (a > b);
  bool isLess = (a < b );

  cout << "Are they are equal" << isEqual << endl;
  cout << "is Greater" << isGreater << endl;
  cout << "is Less" << isLess << endl;

  bool third = isEqual && isGreater;
  bool fourth = isEqual || isGreater;

  cout << "Not equal" << !isEqual << endl;

}
