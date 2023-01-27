#include<iostream>
using namespace std;

void g(int const &a){
  //a++; Not_Possible
  //a++; Possible_for(int &a) only;
}

void f(int const *p){
  //(*p)++ Not_Possible
  //(*p)++ Possible_for (int *p) only;
}

int main(){
  int const i = 10;
  int const *p = &i;
  //i++; Not_Possible
  //(*p)++ Not_Possible

  int j = 12;
  int *p2 = &j;
  g(j);
  f(p2);
  int const *p3 = &j;
  cout << *p3 << endl;
  j++; // Possible
  //(*p3)++ Not_Possible
  cout << *p3 << endl;
  return 0;
}
