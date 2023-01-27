#include<iostream>
using namespace std;

int main() {
  int a[] = {1,2,3,4};
  char ch[] = "abcd";

  cout << a << endl;
  cout << ch << endl;

  char *c = &ch[0];
  cout << c << endl;

  char c1 = 'a';

  char *pc = &c1;
  cout << c1 << endl;
  cout << pc << endl;

  char str[] = "abcde";
  char *pstr = "abcde";

  cout << str << endl;
  cout << *pstr << endl;
  //------ As  *pstr pointing to temp memory. So it gives an error ---------------------//
  return 0;
}
