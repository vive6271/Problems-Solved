#include<iostream>
using namespace std;

int main() {
  char name[100];
  //cin >> name;
  cin.getline(name,100);
  cout << name << endl;
}
