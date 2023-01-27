/*
Q. Square Root (Integral)

Given a number N, find its square root. You need to find and print only the integral part of square root of N.
For eg. if number given is 18, answer is 4.

Sample Input 1 :
10

Sample Output 1 :
3

Sample Input 2 :
4

Sample Output 2 :
2
*/

#include<iostream>
using namespace std;

int main(){
  int n;
  cin >> n;

  int sq = 0;
  int i = 1;
  while(sq <= n > 0){
    i++;
    sq = i * i;
  }
  cout << i - 1 << endl;
}
