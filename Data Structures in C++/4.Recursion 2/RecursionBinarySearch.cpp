/*
Q. Binary Search (Recursive)
Send Feedback
Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
Return -1 if x is not present in the given array.

Note : If given array size is even, take first mid.

Input format :
Line 1 : Array size
Line 2 : Array elements (separated by space)
Line 3 : x (element to be searched)

Sample Input :
6
2 3 4 5 6 8 
5 

Sample Output:
3 
*/
#include<iostream>
using namespace std;

int helperSearch(int input[], int start, int end, int element){
  if(start > end){
    return -1;
  }
  int mid = (start+end)/2;
  int smallSearch;
  if(input[mid] == element){
    return mid;
  }else if(input[mid] > element){
    smallSearch = helperSearch(input, start, mid-1, element);
  }else{
    smallSearch = helperSearch(input, mid+1, end, element);
  }
  return smallSearch;
}

int binarySearch(int input[], int size, int element){
  return helperSearch(input, 0, size-1, element);
}

int main() {
  int n, arr[500], x;
  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  cin >> x;
  int output = binarySearch(arr,n,x);
  cout << output << endl;
}
