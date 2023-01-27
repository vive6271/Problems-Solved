/*
Q. Binary Search

You have been given a sorted(in ascending order) integer array/list(ARR) of size N and an element X. 
Write a function to search this element in the given input array/list using 'Binary Search'. 
Return the index of the element in the input array/list. In case the element is not present in the array/list, then return -1.

Sample Input 1:
7
1 3 7 9 11 12 45
1
3

Sample Output 1:
1

Sample Input 2:
7
1 2 3 4 5 6 7
2
9
7

Sample Output 2:
-1
6
*/

#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int x){
  int start = 0;
  int end = n - 1;
  while(start <= end) {
    int mid = (start + end) / 2;
    if(arr[mid] == x){
      return mid;
    }else if(arr[mid] > x){
      end = (mid - 1);
    }else{
      start = (mid + 1);
    }
  }
  return -1;
}

int main(){
  int n,x;
  cin >> n;

  int arr[10];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  cin >> x;

  int output = binarySearch(arr, n, x);
  cout << output << endl;
}
