#include<iostream>
using namespace std;
#include"StudentStaticClass.cpp"

int main(){
  Student s1;
  s1.rollNumber = 72;
  s1.age = 23;

  cout << s1.rollNumber << " " << s1.age << endl;
  cout << s1.totalStudents << endl; //Works but its not good practice to use this method and logically incorrect. So avoid it.

  s1.totalStudents = 110;
  Student s2;

  cout << s2.totalStudents << endl;
  cout << Student :: totalStudents << endl;

  return 0;

}
