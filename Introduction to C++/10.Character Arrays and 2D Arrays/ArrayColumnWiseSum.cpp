/*
Q. Column Wise Sum

Given a 2D integer array of size M*N, find and print the sum of ith column elements separated by space.

Sample Input :
4 2 
1 2 3 4 5 6 7 8

Sample Output :
16 20
*/

#include<iostream>
using namespace std;

int main(){
  int arr[1000][1000];
  int m, n;

  cin >> m >> n;

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cin >> arr[i][j];
    }
  }

  for(int k = 0; k < n; k++){
    int colSum = 0;
    for(int a = 0; a < m; a++){
      colSum += arr[a][k];
    }
    cout << colSum << " ";
  }
  cout << endl;
}
