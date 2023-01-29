#include<iostream>
#include<climits>
using namespace std;

int miserMan(int **arr, int n, int m){
  int **dp = new int*[n];
  for(int i = 0; i < n; i++){
    dp[i] = new int[m];
  }
  for(int j = 0; j < m; j++){
    dp[0][j] = arr[0][j];
  }

  for(int i = 1; i < n; i++){
    for(int j = 0; j < m; j++){
      int a = INT_MAX, b = INT_MAX, c = INT_MAX;
      if((i-1) >= 0 && (j-1) >= 0){
        a = dp[i-1][j-1];
      }
      if((i-1) >= 0){
        b = dp[i-1][j];
      }
      if((i-1) >= 0 && (j+1) < m){
        c = dp[i-1][j+1];
      }
      dp[i][j] = max(arr[i][j], (arr[i][j] + min(a, min(b,c))));
    }
  }
  int ans = INT_MAX;
  for(int j = 0; j < m; j++){
    ans = min(ans,dp[n-1][j]);
  }
  for(int i = 0; i < n; i++){
    delete [] dp[i];
  }
  delete [] dp;
  return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;
    int **arr = new int*[n];
    for(int i = 0; i < n; i++){
      arr[i] = new int[m];
      for(int j = 0; j < m; j++){
        cin >> arr[i][j];
      }
    }
    cout << miserMan(arr,n,m) << endl;
    for(int i = 0; i < n; i++){
      delete [] arr[i];
    }
    delete [] arr;
  }
  return 0;
}
