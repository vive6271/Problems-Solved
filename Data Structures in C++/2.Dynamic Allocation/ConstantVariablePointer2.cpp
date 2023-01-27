#include<iostream>
using namespace std;

int main() {
  int i = 10;
  int j = 21;
  int const *p = &i;

  p = &j; //Possible
  //(*p)++ Not_Possible

  int * const p2 = &i;
  (*p)++; //Possible
  //p2 = &j; Not_Possible

  int const * const p3 = &i;
  //p3 = &j; Not_Possible
  //(*p3)++ Not_Possible
  return 0;
}
