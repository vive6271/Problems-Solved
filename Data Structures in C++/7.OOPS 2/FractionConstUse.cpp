#include<iostream>
using namespace std;
#include "FractionConstClass.cpp"

int main(){
  Fraction f1(10,2);
  Fraction f2(15,4);
  cout << "f1 :- " << f1.getNumerator() << " " << f1.getDenominator() << endl;
  cout << "f2 :- " << f2.getNumerator() << " " << f2.getDenominator() << endl;
  Fraction const f3;
  cout << "f3 :- " << f3.getNumerator() << " " << f3.getDenominator() << endl;
}
