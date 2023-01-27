/*
Q. Sum of digits (recursive)

Write a recursive function that returns the sum of the digits of a given integer.

Sample Input 1 :
12345

Sample Output 1 :
15

Sample Input 2 :
9

Sample Output 2 :
9

*/
#include<iostream>
using namespace std;

int digitSum(int n){
  if(n == 0){
    return 0;
  }
  int smallCalculation = digitSum(n/10);
  return smallCalculation + n%10;
}

int main(){
  int n;
  cin >> n;

  int sum = digitSum(n);
  cout << sum << endl;
  return 0;
}
