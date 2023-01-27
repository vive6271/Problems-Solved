#include<iostream>
using namespace std;

int fact(int num){
  cout << num << endl;
  if(num == 0){
    return 1;
  }
  int smallOutput = fact(num - 1);
  return num * smallOutput;
}

int main(){
  int n;
  cin >> n;
  int output = fact(n);
  cout << output << endl;
}
