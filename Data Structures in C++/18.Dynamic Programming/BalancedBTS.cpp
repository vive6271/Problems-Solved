/*
Q. No. of balanced BTs using Brute Force

Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Time complexity should be O(h).

Sample Input 1:
3

Sample Output 1:
15

Sample Input 2:
4

Sample Output 2:
315

*/

#include<iostream>
#include<cmath>
using namespace std;
//Brute Force
int balancedBTs(int n){
  if(n <= 1){
    return 1;
  }
  int x = balancedBTs(n-1);
  int y = balancedBTs(n-2);
  int mod = (int) (pow(10,9)) + 7;
  int temp1 = (int)(((long)(x)*x) % mod);
  int temp2 = (int)((2*(long)(x)*y) % mod);
  int ans = (temp1 + temp2) % mod;
  return ans;
}

int main(){
  int n;
  cin >> n;
  cout << balancedBTs(n) << endl;
  return 0;
}
