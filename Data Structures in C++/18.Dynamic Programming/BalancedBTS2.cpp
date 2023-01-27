/*
Q. No. of balanced BTs using DP

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

#include <iostream>
#include <cmath>
using namespace std;
//Memoization
/*
int balancedBTsHelper(int *arr, int n){
  if(n <= 1){
    return 1;
  }
  if(arr[n-1] != -1){
    return arr[n-1];
  }

  int x = balancedBTsHelper(arr, n-1);
  int y = balancedBTsHelper(arr, n-2);
  int mod = (int) (pow(10,9)) + 7;

  int tmp1 = (int) (((long)(x) * x) % mod);
  int tmp2 = (int) ((2 * (long)(x) * y) % mod);
  arr[n-1] = (tmp1+tmp2) % mod;
  return arr[n-1];
}

int balancedBTs(int n){
  int *arr = new int[n];
  for(int i = 0; i < n; i++){
    arr[i] = -1;
  }
  int result = balancedBTsHelper(arr,n);
  delete [] arr;
  return result;
}
*/
int balancedBTs(int n){
  if(n <= 1){
    return 1;
  }
  int mod = (int) (pow(10,9)) + 7;
  int *arr = new int[n+1];
  arr[0] = 1;
  arr[1] = 1;
  for(int i = 2; i <= n; i++){
    int tmp1 = (int) (((long) (arr[i-1]) * arr[i-1])  % mod);
    int tmp2 = (int) ((2 *(long)(arr[i-1]) * arr[i-2]) % mod);
    arr[i] = (tmp1+tmp2) % mod;
  }
  int result = arr[n];
  delete [] arr;
  return result;
}
int main(){
  int n;
  cin >> n;
  cout << balancedBTs(n) << endl;
  return 0;
}
