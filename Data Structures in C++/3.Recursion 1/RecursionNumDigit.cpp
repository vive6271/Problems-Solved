/*
Q. Number of Digits

Given the number 'n', find out and return the number of digits present in a number .

Sample Input 1 :
 156

Sample Output 1 :
3

Sample Input 2 :
 7

Sample Output 2 :
1
*/

#include<iostream>
using namespace std;

int digitCount(int n){
  if(n == 0){
    return 0;
  }
  int smallDigit = digitCount(n/10);
  return smallDigit+1;
}

int main(){
  int n;
  cin >> n;
  int output = digitCount(n);
  cout << output << endl;
}
