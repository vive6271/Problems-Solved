#include<iostream>
using namespace std;
#include "StudentConstruct.cpp"

int main(){
  Student s1; // Constructor Called !

  Student s2(191); // Constructor 2 Called !

  Student s3(20,102); // Constructor 3 Called !

  Student s4(s3); // Copy Constructor !

  s1 = s2; // Copy Assignment Operator !

  Student s5 = s4; // Copy Constructor !

  return 0;
}
