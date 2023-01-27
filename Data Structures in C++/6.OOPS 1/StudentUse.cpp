#include<iostream>
using namespace std;
#include "Student.cpp"

int main(){
  // Create Objects Statically
  Student s1;
  Student s2;

  Student  s3, s4, s5;

  s1.age = 24;
  s1.rollNumber = 101;

  cout << s1.age << endl;
  cout << s1.rollNumber << endl;

  // Create Objects Dynamically

  Student *s6 = new Student;
  Student *s7 = new Student;

  (*s6).age = 21;
  (*s6).rollNumber = 86;

  cout << (*s6).age << endl;
  cout << (*s6).rollNumber << endl;

  s7 -> age = 18;
  s7 -> rollNumber = 90;

  cout << s7 -> age << endl;
  cout << s7 -> rollNumber  << endl;
}
