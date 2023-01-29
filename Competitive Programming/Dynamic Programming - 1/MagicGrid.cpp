#include<iostream>
#include<climits>
using namespace std;

/*
// Brute Force

int magicGrid(int **arr, int si, int sj, int ei, int ej){
  if(si == ei && sj == ej){
    return 1;
  }
  if(si > ei || sj > ej){
    return 0;
  }
  int step1 = INT_MAX, step2 = INT_MAX;
  if(si+1 <= ei){
    step1 = magicGrid(arr, si+1, sj, ei, ej) - arr[si+1][sj];
  }
  if(sj+1 <= ej){
    step2 = magicGrid(arr, si, sj+1, ei, ej) - arr[si][sj+1];
  }
  return max(1, min(step1,step2));
}

// Memoization

int magicGrid(int **arr, int si, int sj, int ei, int ej, int **output){
  if(si == ei && sj == ej){
    return 1;
  }
  if(si > ei || sj > ej){
    return 0;
  }
  if(output[si][sj] != -1){
    return output[si][sj];
  }

  int step1 = INT_MAX, step2 = INT_MAX;
  if(si+1 <= ei){
    step1 = magicGrid(arr, si+1, sj, ei, ej, output) - arr[si+1][sj];
  }
  if(sj+1 <= ej){
    step2 = magicGrid(arr, si, sj+1, ei, ej, output) - arr[si][sj+1];
  }
  output[si][sj] = max(1, min(step1,step2));
  return output[si][sj];
}

int magicGrid(int **arr, int m, int n){
  int **output = new int*[m+1];
  for(int i = 0; i <= m; i++){
    output[i] = new int[n+1];
    for(int j = 0; j <= n; j++){
      output[i][j] = -1;
    }
  }
  int ans = magicGrid(arr, 0, 0, m-1, n-1,output);
  for(int i = 0; i <= m; i++){
    delete [] output[i];
  }
  delete [] output;
  return ans;
}
*/

int magicGrid(int **arr, int m, int n){
  int **output = new int*[m];
  for(int i = 0; i < m; i++){
    output[i] = new int[n];
  }
  output[m-1][n-1] = 1;
  for(int i = m-2; i >= 0; i--){
    output[i][n-1] = output[i+1][n-1] - arr[i][n-1];
  }
  for(int j = n-2; j >= 0; j--){
    output[m-1][j] = output[m-1][j+1] - arr[m-1][j];
  }

  for(int i = m-2; i >= 0; i--){
    for(int j = n-2; j >= 0; j--){
      output[i][j] = max(1, min(output[i+1][j], output[i][j+1]) - arr[i][j]);
    }
  }
  int ans = output[0][0];
  for(int i = 0; i < m; i++){
    delete [] output[i];
  }
  delete [] output;
  return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int m, n;
    cin >> m >> n;
    int **arr = new int*[m];
    for(int i = 0; i < m; i++){
      arr[i] = new int[n];
      for(int j = 0; j < n; j++){
        cin >> arr[i][j];
      }
    }
    //cout << magicGrid(arr, 0, 0, m-1, n-1) << endl;  Brute Force
    cout << magicGrid(arr, m, n) << endl;
    for(int i = 0; i < m; i++){
      delete [] arr[i];
    }
    delete [] arr;
  }
  return 0;
}
