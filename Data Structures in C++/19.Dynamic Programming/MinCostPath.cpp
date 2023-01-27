/*
Q. Min Cost Path(Brute Force)

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
//Brute Force
int minCostPathHelper(int **arr, int n, int m, int Is, int Js){
  if(Is == n-1 && Js == m-1){
    return arr[Is][Js];
  }
  if(Is >= n || Js >= m){
    return INT_MAX;
  }
  int x = minCostPathHelper(arr, n, m, Is, Js+1);
  int y = minCostPathHelper(arr, n, m, Is+1, Js+1);
  int z = minCostPathHelper(arr, n, m, Is+1, Js);
  return arr[Is][Js] + (min(x,min(y,z)));
}

int minCostPath(int **arr, int n, int m){
  return minCostPathHelper(arr, n, m, 0, 0);
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
