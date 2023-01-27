/*
Q. All Indices of Number

Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. 
Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.

Sample Input :
5
9 8 10 8 8
8

Sample Output :
1 3 4

*/
#include<iostream>
using namespace std;

int allIndexes(int input[], int size, int x, int output[]){
  if(size == 0){
    return 0;
  }
  int smallCal = allIndexes(input+1, size-1, x, output);
  for(int i = 0; i < smallCal; i++){
      output[i]++;
  }
  if(input[0] == x){
    for(int i = smallCal-1; i >= 0; i--){
      output[i+1] = output[i];
    }
    output[0] = 0;
    return smallCal+1;
  }
  return smallCal;
}

int main(){
  int n, arr[100], x, output[100];
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  cin >> x;
  int m = allIndexes(arr, n, x, output);
  for(int j = 0; j < m; j++){
    cout << output[j] << " ";
  }
  cout << endl;
}
