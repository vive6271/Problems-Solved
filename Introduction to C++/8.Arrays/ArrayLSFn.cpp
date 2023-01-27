/*
Linear Search

You have been given a random integer array/list(ARR) of size N, and an integer X. You need to search for the integer X in the given array/list using 'Linear Search'.
 You have been required to return the index at which X is present in the array/list. If X has multiple occurrences in the array/list, 
 then you need to return the index at which the first occurrence of X would be encountered. In case X is not present in the array/list, then return -1.
'Linear search' is a method for finding an element within an array/list. It sequentially checks each element of the array/list until a match is found or the whole array/list has been searched.

Sample Input 1:
1
7
2 13 4 1 3 6 28
3

Sample Output 1:
4

Sample Input 2:
2
7
2 13 4 1 3 6 28
9
5
7 8 5 9 5      
5

Sample Output 2:
-1
2

*/

#include<iostream>
using namespace std;

int linearSearch(int array[] , int n, int x){
  for(int k = 0; k < n; k++){
    if(array[k] == x){
      return k;
    }
  }
  return -1;
}

int main(){
  int t, n, x;
  cin >> t >> n;

  int array[100000];

  int i = 1;
  while( i <= t){
    for(int j = 0; j < n ; j++){
      cin >> array[j];
    }
    i++;

    cin >> x;
    int output = linearSearch( array, n , x);
    cout << output << endl;
    if ( x != NULL){
      cin.clear();
    }
  }
}
