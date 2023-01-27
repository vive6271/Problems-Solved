/*
Q. Sort 0 1 2

You are given an integer array/list(ARR) of size N. It contains only 0s, 1s and 2s. Write a solution to sort this array/list in a 'single scan'.
'Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just once.

Note:
You need to change in the given array/list itself. Hence, no need to return or print anything. 


Sample Input 1:
1
7
0 1 2 0 2 0 1

Sample Output 1:
0 0 0 1 1 2 2 

Sample Input 2:
2
5
2 2 0 1 1
7
0 1 2 0 1 2 0

Sample Output 2:
0 1 1 2 2 
0 0 0 1 1 2 2
*/

#include<iostream>
using namespace std;

void printArray(int arr[], int n){
  for(int j = 0; j < n; j++){
    cout << arr[j] << " ";
  }
  cout << endl;
}

void pushZero(int arr[], int n){
  int i = 0, zeroIndex = 0, twoIndex = n-1;
  while(i <= twoIndex){
    if(arr[i] == 0){
      int tmp = arr[i];
      arr[i] = arr[zeroIndex];
      arr[zeroIndex] = tmp;
      i++;
      zeroIndex++;
    }else if(arr[i] == 2){
      int tmp = arr[i];
      arr[i] = arr[twoIndex];
      arr[twoIndex] = tmp;
      twoIndex--;
    }else{
      i++;
    }
  }
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int arr[100];
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }
    pushZero(arr,n);
    printArray(arr,n);
  }
}
