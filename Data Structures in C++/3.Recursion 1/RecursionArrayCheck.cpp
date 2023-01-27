/*
Q. Check Number

Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.
Do this recursively.

Sample Input 1 :
3
9 8 10
8

Sample Output 1 :
true

Sample Input 2 :
3
9 8 10
2

Sample Output 2 :
false
*/

#include<iostream>
using namespace std;

bool checkNum(int arr[], int size, int x){
  if(size == 0){
    return false;
  }
  if(arr[0] == x){
    return true;
  }
  bool smallCheck = checkNum(arr+1, size-1, x);
  return smallCheck;
}

int main(){
  int n, arr[100], x;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  cin >> x;
  bool isTrue = checkNum(arr, n, x);
  if(isTrue == 1){
    cout << "True" << endl;
  }else{
    cout << "False" << endl;
  }
  return 0;
}
