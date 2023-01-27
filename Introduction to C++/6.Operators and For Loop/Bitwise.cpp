#include<iostream>
using namespace std;

int main() {
  int ror = 15 | 30;
  int rand = 15 & 30;
  int rnot = ~15;
  int rxor = 15 ^ 30;
  int rls = 15 << 2;
  int rrs = 15 >> 2;

  cout << "ror :  " << ror << endl;
  cout << "rand :  " << rand << endl;
  cout << "rnot :  " << rnot << endl;
  cout << "xor :  " << rxor << endl;
  cout << "rls :  "<< rls << endl;
  cout << "rrs :  " << rrs << endl;
}
