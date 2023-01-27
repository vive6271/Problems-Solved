/*
Q. Staircase

A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. 
Implement a method to count and return all possible ways in which the child can run-up to the stairs.

Sample Input 1:
4

Sample Output 1:
7

Sample Input 2:
10

Sample Output 2:
274

*/

#include<iostream>
using namespace std;
//Brute Force
/*
long staircase(int n){
  if(n == 0){
    return 1;
  }
  long a = staircase(n-1);
  long b = 0, c = 0;
  if(n >= 2){
    b = staircase(n-2);
  }
  if(n >= 3){
    c = staircase(n-3);
  }
  return (a+b+c);
}
*/

long staircase(int n) {
  // Write your code here
  if(n == 0){
	  return 1;
  }
  if (n == 1 || n == 2) {
    return n;
  }
  long *arr = new long[n + 1];
  arr[0] = 1;
  arr[1] = 1;
  arr[2] = 2;
  for (int i = 3; i <= n; i++) {
    arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
  }
  long ans = arr[n];
  delete[] arr;
  return ans;
}

int main(){
  int n;
  cin >> n;
  cout << staircase(n) << endl;
}
