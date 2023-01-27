#include <iostream>
using namespace std;

int main() {
  int a;

  cout << "Enter value of a and b" << endl;

  cin >> a;

  if (a % 2 == 0) {
    cout << "Even" << endl;
  }else {
    cout << "Odd" << endl;
  }
}
