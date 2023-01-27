#include<iostream>
using namespace std;
#include "FractionOverload4Class.cpp"

int main(){
  Fraction f1(10,3);
  Fraction f2(5,2);

  f1 += f2;
  f1.print();
  f2.print();

  (f1 += f2) += f2;
  f1.print();
  f2.print();

  return 0;
}
