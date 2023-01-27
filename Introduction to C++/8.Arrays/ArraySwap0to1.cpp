/*
Q. Sort 0 1

You have been given an integer array/list(ARR) of size N that contains only integers, 0 and 1. 
Write a function to sort this array/list. Think of a solution which scans the array/list only 
once and don't require use of an extra array/list.

Note:
You need to change in the given array/list itself. Hence, no need to return or print anything. 

Sample Input 1:
1
7
0 1 1 0 1 0 1

Sample Output 1:
0 0 0 1 1 1 1

Sample Input 2:
2
8
1 0 1 1 0 1 0 1
5
0 1 0 1 0

Sample Output 2:
0 0 0 1 1 1 1 1
0 0 0 1 1 
*/

#include<iostream>
using namespace std;

void printArray(int arr[], int n){
  for(int l = 0; l < n; l++){
    cout << arr[l] << " ";
  }
  cout << endl;
}

void sortZeroAndOne(int arr[], int n){
  int nextZero = 0;
  for (int i = 0; i < n; i++){
    if (arr[i] == 0)
    {
      int temp = arr[nextZero];
      arr[nextZero] = arr[i];
      arr[i] = temp;
      nextZero++;
    }
  }
}

int main() {
  int n;
  cin >> n;

  int arr[10];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  sortZeroAndOne(arr,n);

  printArray(arr,n);
}
