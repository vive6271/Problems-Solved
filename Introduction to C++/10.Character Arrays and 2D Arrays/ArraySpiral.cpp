/*
Q. Spiral Print

For a given two-dimensional integer array/list of size (N x M), print it in a spiral form. That is, you need to print in the order followed for every iteration:
a. First row(left to right)
b. Last column(top to bottom)
c. Last row(right to left)
d. First column(bottom to top)

Sample Input 1:
1
4 4 
1 2 3 4 
5 6 7 8 
9 10 11 12 
13 14 15 16

Sample Output 1:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 

Sample Input 2:
2
3 3 
1 2 3 
4 5 6 
7 8 9
3 1
10
20
30

Sample Output 2:
1 2 3 6 9 8 7 4 5 
10 20 30 
*/
#include<iostream>
using namespace std;

void printSpiral(int arr[][100], int n, int m){
  int elements = n * m;
  int num = 0;
  int rowStart = 0, rowEnds = n - 1;
  int colStart = 0, colEnds = m - 1;

  while( num < elements){
    for(int a = colStart; a <= colEnds ; a++){
        cout << arr[rowStart][a] << " ";
        num++;
    }
    rowStart++;
    for(int b = rowStart; b <= rowEnds; b++){
      cout << arr[b][colEnds] << " ";
      num++;
    }
    colEnds--;
    for(int c = colEnds; c >= colStart; c--){
      cout << arr[rowEnds][c] << " ";
      num++;
    }
    rowEnds--;
    for(int d = rowEnds; d >= rowStart; d--){
      cout << arr[d][colStart] << " ";
      num++;
    }
    colStart++;
  }
  cout << endl;
}

int main() {
  int arr[100][100];

  int n , m;
  cin >> n >> m;

  for(int i  = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> arr[i][j];
    }
  }
  printSpiral(arr, n, m);
}
