#include<iostream>
using namespace std;

int multiply(int a, int b){
  return a * b;
}

int main() {
  int a, b;
  cin >> a >> b;

  int multi = multiply(a,b);

  cout << multi << endl;
}
