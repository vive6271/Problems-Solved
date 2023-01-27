#include<iostream>
using namespace std;

int main() {
  //-----------Implicit_TypeCasting-------------//
  int i = 65;
  char c = i;
  cout << c << endl;
  //-----------Implicit_TypeCasting-------------//

 //-----------Explicit_TypeCasting------------//
 int *p = &i;
 char *pc = (char*) p;
 cout << *p << endl;
 cout << *pc << endl;
 cout << *(pc+1) << endl;
 cout << *(pc+2) << endl;
 cout << *(pc+3) << endl;
 //-----------Explicit_TypeCasting------------//
 cout << p << endl;
 cout << pc << endl;
}
