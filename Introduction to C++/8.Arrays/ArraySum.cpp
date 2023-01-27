/*
Q. Array Sum

Given an array of length N, you need to find and print the sum of all elements of the array.

Sample Input :
3
9 8 9

Sample Output :
26
*/

#include<iostream>
using namespace std;

int main(){
  int n;
  cin >> n;

  int num[1000000];
  int sum = 0;

  for(int i = 0; i < n; i++){
    cin >> num[i];
  }
  for(int j = 0; j < n; j++){
    sum += num[j];
  }

  cout << sum << endl;
}
