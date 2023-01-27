/*
Q. Maximum Square Matrix With All Zeros

Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s. You need to return the size of the square matrix with all 0s.

Sample Input 1:
3 3
1 1 0
1 1 1
1 1 1

Sample Output 1:
1

Sample Input 2:
4 4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0

Sample Output 2:
4
*/

#include <iostream>
#include <cmath>
using namespace std;

int findMaxSquareWithAllZeros(int **arr, int n, int m){
	//Write your code here
  int **output = new int*[n];
  for(int i = 0; i < n; i++){
    output[i] = new int[m];
  }
  bool zeroFound = false;
  for(int i = 0; i < n; i++){
    if(arr[i][0] == 0){
      output[i][0] = 1;
      zeroFound = true;
    }else{
      output[i][0] = 0;
    }
  }
  for(int j = 1; j < m; j++){
    if(arr[0][j] == 0){
      output[0][j] = 1;
      zeroFound = true;
    }else{
      output[0][j] = 0;
    }
  }
  int maxSquare = (zeroFound) ? 1 : 0;
  for(int i = 1; i < n; i++){
    for(int j = 1; j < m; j++){
      if(arr[i][j] == 0){
        int tmp = 1 + min(min(output[i-1][j-1], output[i][j-1]), output[i-1][j]);
        maxSquare = max(maxSquare,tmp);
        output[i][j] = tmp;
      }else{
        output[i][j] = 0;
      }
    }
  }
  return maxSquare;
}

int main(){
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];

	for (i = 0; i < n; i++){
		arr[i] = new int[m];
	}

	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}

	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

	delete[] arr;

	return 0;
}
