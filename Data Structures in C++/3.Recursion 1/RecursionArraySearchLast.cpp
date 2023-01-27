/*
Q. Last Index of Number

Given an array of length N and an integer x, you need to find and return the last index of integer x present in the array. Return -1 if it is not present in the array.
Last index means - if x is present multiple times in the array, return the index at which x comes last in the array.
You should start traversing your array from 0, not from (N - 1).
Do this recursively. Indexing in the array starts from 0.

Sample Input :
4
9 8 10 8
8

Sample Output :
3
*/

#include<iostream>
using namespace std;

int arraySearch(int arr[], int size, int x){
  if(size == 0){
    return -1;
  }
  int smallSearch = arraySearch(arr+1, size-1, x);
  cout << smallSearch << endl;
  if(smallSearch != -1){
    return smallSearch+1;
  }
  if(arr[0] == x){
    return 0;
  }else{
    return -1;
  }
}

int main(){
  int n, arr[100], x;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  cin >> x;
  int output = arraySearch( arr, n, x);
  cout << output << endl;
  return 0;
}
