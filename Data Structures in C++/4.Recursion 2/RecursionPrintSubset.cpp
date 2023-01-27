/*
Q. Print Subsets of Array

Given an integer array (of length n), find and print all the subsets of input array.

Subsets are of length varying from 0 to n, that contain elements of the array. 
But the order of elements should remain same as in the input array.

Note : The order of subsets are not important. Just print the subsets in different lines.

Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)

Sample Input:
3
15 20 12

Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 
*/

#include<iostream>
using namespace std;

void helperPrintSubset(int input[], int size, int output[], int n){
  if(size == 0){
    for(int i = 0; i < n; i++){
      cout << output[i] << " ";
    }
    cout << endl;
    return;
  }
  helperPrintSubset(input+1, size-1, output, n);
  for(int i = 0; i <= n; i++){
    output[n+i] = input[0];
  }
  helperPrintSubset(input+1, size-1, output, n+1);
}

void printSubsetsOfArray(int input[], int size){
  int arr[100];
  helperPrintSubset(input, size, arr, 0);
}

int main(){
  int input[1000], n;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> input[i];
  }
  printSubsetsOfArray(input,n);
}
