#include<iostream>
using namespace std;
#include "StudentConstInBuilt.cpp"

int main(){
  Student s1(10,1001);
  cout << "S1 : ";
  s1.display();

  Student s2(s1); //Copy Constructor
  cout << "S2 : ";
  s2.display();

  Student *s3 = new Student(20,2001);
  cout << "S3 : ";
  s3 -> display();

  Student s4(*s3); //Copy Constructor
  cout << "S4 : ";
  s4.display();

  Student *s5 = new Student(*s3); //Copy Constructor
  cout << "S5 : ";
  s5 -> display();

  Student *s6 = new Student(s1); //Copy Constructor
  cout << "S6 : ";
  s6 -> display();

  return 0;
}
