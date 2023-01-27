/*
Q. Wave Print

For a given two-dimensional integer array/list of size (N x M), print the array/list in a sine wave order, 
i.e, print the first column top to bottom, next column bottom to top and so on.

Sample Input 1:
1
3 4 
1  2  3  4 
5  6  7  8 
9 10 11 12

Sample Output 1:
1 5 9 10 6 2 3 7 11 12 8 4

Sample Input 2:
2
5 3 
1 2 3 
4 5 6 
7 8 9 
10 11 12 
13 14 15
3 3
10 20 30 
40 50 60
70 80 90

Sample Output 2:
1 4 7 10 13 14 11 8 5 2 3 6 9 12 15 
10 40 70 80 50 20 30 60 90 
*/

#include<iostream>
using namespace std;

void printArray2D(int arr[][100], int m, int n){
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

void wavePrint(int arr[][100], int m, int n){
  for(int i = 0; i < n; i++){
    if( i % 2 == 0){
      for(int j = 0; j < m; j++){
        cout << arr[j][i] << " ";
      }
    }else{
      for(int j = m - 1; j >= 0; j--){
        cout << arr[j][i] << " ";
      }
    }
  }
  cout << endl;
}

int main() {
  int arr[100][100];
  int m, n;
  cin >> m >> n;

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cin >> arr[i][j];
    }
  }

  printArray2D(arr, m, n);
  wavePrint(arr, m, n);
}
