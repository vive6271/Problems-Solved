#include<iostream>
using namespace std;
#include "StudentConstruct.cpp"

int main(){
  Student s1;
  s1.display();

  Student s2;
  s2.display();

  Student *s3 = new Student;
  s3 -> display();

  cout << "Parameterized Constructor Demo" << endl;
  Student s4(20);
  s4.display();

  Student *s5 = new Student(101);
  s5 -> display();

  Student s6(20,567);
  s6.display();
  return 0;
}
