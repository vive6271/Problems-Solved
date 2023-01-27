/*
Largest Row or Column

For a given two-dimensional integer array/list of size (N x M), you need to find out which row or 
column has the largest sum(sum of all the elements in a row/column) amongst all the rows and columns.

Note :
If there are more than one rows/columns with maximum sum, consider the row/column that comes first. 
And if ith row and jth column has the same largest sum, consider the ith row as answer.

Sample Input :
3 3 
3 6 9 1 4 7 2 8 9

Sample Output 
2 25
*/

#include<iostream>
#include<climits>
using namespace std;

void sumRowOrCol(int arr[][100], int m, int n){
  int sumRow = INT_MIN;
  int sumCol = INT_MIN;
  int temp;
  int iLoc = 0, jLoc = 0;

  // Sum of Row //
  for(int a = 0; a < m; a++){
    int temp = 0;
    for(int b = 0; b < n; b++){
      temp += arr[a][b];
    }
    if(sumRow < temp){
      sumRow = temp;
      iLoc = a;
    }
  }
  // Sum of Column //
  for(int a = 0; a < n; a++){
    int temp = 0;
    for(int b = 0; b < m; b++){
      temp += arr[b][a];
    }
    if(sumCol < temp){
      sumCol = temp;
      jLoc = a;
    }
  }
  if(sumRow < sumCol){
    cout << "column " << jLoc << " " << sumCol << endl;
  }else{
    cout << "row " << iLoc << " " << sumRow << endl;
  }
}

int main(){
  int arr[100][100];
  int m, n;

  cin >> m >> n;

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cin >> arr[i][j];
    }
  }
  sumRowOrCol(arr, m, n);
}
