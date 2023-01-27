/*
Q. Second Largest in array

You have been given a random integer array/list(ARR) of size N. You are required to find and return the second largest element present in the array/list.
If N <= 1 or all the elements are same in the array/list then return -2147483648 or -2 ^ 31(It is the smallest value for the range of Integer)

Sample Input 1:
1
7
2 13 4 1 3 6 28

Sample Output 1:
13

Sample Input 2:
1
5
9 3 6 2 9

Sample Output 2:
6

Sample Input 3:
2
2
6 6
4
90 8 90 5

Sample Output 3:
-2147483648
8
*/

#include<iostream>
#include<climits>
using namespace std;

int secondLarge(int arr[], int n){
  int Large = INT_MIN;
  int SLarge = INT_MIN;
  for(int j = 0; j < n; j++){
    if(Large < arr[j]){
      SLarge = Large;
      Large = arr[j];
    }else if(arr[j] < Large && SLarge < arr[j]){
      SLarge = arr[j];
    }
  }
  return SLarge;
}

int main(){
  int n;
  cin >> n;

  int arr[20];
  for(int i  = 0; i < n; i++){
    cin >> arr[i];
  }

  int output = secondLarge(arr,n);
  cout << output << endl;
}
