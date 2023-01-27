#include<iostream>
using namespace std;
#include "StudentStaticFunctionClass.cpp"

int main(){
  Student s1;
  cout << Student :: getTotalStudent() << endl;

  Student s2,s3;
  cout << Student :: getTotalStudent() << endl;

  Student s4,s5,s6;
  cout << Student :: getTotalStudent() << endl;

  return 0;
}
