#include<iostream>
using namespace std;
#include "StudentNew.cpp"

int main(){
  Student s1,s2;

  s1.rollNumber = 101;
  //s1.age = 24; //Not Possible


  s2.rollNumber = 105;
  //s2.age = 26; // Not  Possible
  s1.Display();
  s2.Display();

  Student *s3 = new Student;

  (*s3).rollNumber = 110;

  (*s3).Display();

  s3 -> Display();

  cout << "Age : " << s1.getAge() << endl;
  cout << "Age : " << s2.getAge() << endl;

  s1.setAge(25);
  s2.setAge(30);
  s3 -> setAge(24);

  cout << "//=========Set Age===========//" << endl;
  s1.Display();
  s2.Display();
  s3 -> Display();

  cout << "//==========Set Age PassWord=============//" << endl;
  int pass;
  cin >> pass;
  s1.setAgePass(33,pass);
  s2.setAgePass(47,pass);
  s3 -> setAgePass(21,pass);

  s1.Display();
  s2.Display();
  s3 -> Display();
  return 0;
}
