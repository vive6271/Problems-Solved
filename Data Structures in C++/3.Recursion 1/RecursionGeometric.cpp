/*
Q. Geometric Sum

Given k, find the geometric sum i.e.
1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 
using recursion.

Sample Input 1 :
3

Sample Output 1 :
1.87500

Sample Input 2 :
4

Sample Output 2 :
1.93750

Explanation for Sample Input 1:
1+ 1/(2^1) + 1/(2^2) + 1/(2^3) = 1.87500

*/
#include<iostream>
using namespace std;

double power(double a){
  if(a == 0){
    return 1;
  }
  double smallPw = power(a-1);
  return 2 * smallPw;
}

double recursionGeo(double n){
  if(n == 0){
    return 1;
  }
  double smallCalculation = recursionGeo(n-1);
  return smallCalculation + 1/power(n);
}

int main(){
  double n;
  cin >> n;
  double output = recursionGeo(n);
  printf("%0.5f\n", output);
  return 0;
}
