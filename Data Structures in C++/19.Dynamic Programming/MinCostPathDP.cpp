/*
Q. Min Cost Path(DP)

An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).

From a cell (i, j), you can move in three directions:
1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"

The cost of a path is defined as the sum of each cell's values through which the route passes.

Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1

Sample Output 1 :
13

Sample Input 2 :
3 4
10 6 9 0
-23 8 9 90
-200 0 89 200

Sample Output 2 :
76
*/
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int minCostPath(int **arr, int m, int n){
  int **output = new int*[m];
  for(int i = 0; i < m; i++){
    output[i] = new int[n];
    for(int j = 0; j < n; j++){
      output[i][j] = -1;
    }
  }
  //Fill the last cell i.e destination
  output[m-1][n-1] = arr[m-1][n-1];

  //Fill last row (right to left)
  for(int j = n-2; j >= 0; j--){
    output[m-1][j] = output[m-1][j+1] + arr[m-1][j];
  }

  //Fill last column (bottom to top)
  for(int i = m-2; i >= 0; i--){
    output[i][n-1] = output[i+1][n-1] + arr[i][n-1];
  }

  //Fill remaining cells
  for(int i = m-2; i >= 0; i--){
    for(int j = n-2; j >= 0; j--){
      output[i][j] = min(output[i][j+1], min(output[i+1][j+1],output[i+1][j])) + arr[i][j];
    }
  }
  return output[0][0];
}

int main(){
  int n, m;
  cin >> n >> m;
  int **arr = new int*[n];

  for(int i = 0; i < n; i++){
    arr[i] = new int[m];
    for(int j = 0; j < m; j++){
      cin >> arr[i][j];
    }
  }
  cout << minCostPath(arr, n, m) << endl;
  for(int i = 0; i < n; i++){
    delete [] arr[i];
  }
  delete [] arr;
  return 0;
}
