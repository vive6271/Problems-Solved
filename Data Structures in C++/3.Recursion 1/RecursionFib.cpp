#include<iostream>
using namespace std;

int fibPlace(int n){
  if(n == 0){
    return 0;
  }
  if(n == 1){
    return 1;
  }
  int smallNum1 = fibPlace(n-1);
  int smallNum2 = fibPlace(n-2);
  return smallNum1 + smallNum2;
}

int main(){
  int n;
  cin >> n;
  int output = fibPlace(n);
  cout << output << endl;
  return 0;
}
