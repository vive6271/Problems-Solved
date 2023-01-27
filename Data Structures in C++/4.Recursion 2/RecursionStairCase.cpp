/*
Q. Staircase

A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. 
Implement a method to count how many possible ways the child can run up to the stairs. You need to return number of possible ways W.


Sample Input 1 :
4

Sample Output 1 :
7

Sample Input 2 :
5

Sample Output 2 :
13
*/

#include<iostream>
using namespace std;

int stairCase(int n){
  if(n < 0){
    return 0;
  }
  if(n == 0){
    return 1;
  }
  int smallStair1 = stairCase(n-1);
  int smallStair2 = stairCase(n-2);
  int smallStair3 = stairCase(n-3);

  return smallStair1 + smallStair2 + smallStair3;
}

int main(){
  int n;
  cin >> n;
  int output = stairCase(n);
  cout << output << endl;
}
