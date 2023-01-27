#include<iostream>
using namespace std;
#include"StudentStaticClass2.cpp"

int main(){
  Student s1;
  cout << Student :: totalStudents << endl;
  
  Student s2,s3;
  cout << Student :: totalStudents << endl;

  Student s4,s5,s6;
  cout << Student :: totalStudents << endl;

  return 0;

}
