#include<iostream>
using namespace std;
#include "StudentConstThis.cpp"

int main(){
  Student s1(104,25);

  cout << "Adderss of s1 : " << &s1 << endl;
  s1.display();
}
