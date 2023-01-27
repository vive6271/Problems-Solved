#include<iostream>
using namespace std;

int main() {
  int i;
  cout << i << endl;

  i++;
  cout << i << endl;

  //-----Too_Bad-----//
  //int *p;
  //-----Too_Bad-----//

  //----Solution-----//
  int *p = 0;
  //----Solution-----//
  cout << p << endl;
  cout << *p << endl;

  (*p)++;
  cout << *p << endl;
  return 0;
}
