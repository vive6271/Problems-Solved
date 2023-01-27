#include<iostream>
using namespace std;

int main(){
  char name[10];
  cout << "Enter your name : " ;
  cin >> name;
  name[4] = 'x';
  cout << "Name : " << name << endl;
}
