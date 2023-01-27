/*
Q. Sum of Array

Given an array of length N, you need to find and return the sum of all elements of the array.
Do this recursively.

Sample Input 1 :
3
9 8 9

Sample Output 1 :
26

Sample Input 2 :
3
4 2 1

Sample Output 2 :
7    
*/

#include<iostream>
using namespace std;

int sumArray(int arr[], int n){
  if(n == 0){
    return 0;
  }
  int smallSum = sumArray(arr+1, n-1);
  return arr[0] + smallSum;
}

int main(){
  int n, arr[100];
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  int output = sumArray(arr,n);
  cout << output << endl;
  return 0;
}
