#include<iostream>
using namespace std;

int factorial(int num){
  cout << num << endl;
  int smallOutput = factorial(num - 1);
  return num * smallOutput;
}

int main(){
  int n;
  cin >> n;
  int output = factorial(n);
  cout << output << endl;
}
