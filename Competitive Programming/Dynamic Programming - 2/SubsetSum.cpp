#include<iostream>
using namespace std;

bool subsetSum(int *arr, int n, int k){
  bool **dp = new bool*[n+1];
  for(int i = 0; i <= n; i++){
    dp[i] = new bool[k+1];
  }
  for(int i = 0; i <= n; i++){
    dp[i][0] = true;
  }
  for(int j = 1; j <= k; j++){
    dp[0][j] = false;
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= k; j++){
      if(arr[i-1] <= j){
        dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
        continue;
      }
      dp[i][j] = dp[i-1][j];
    }
  }
  bool ans = dp[n][k];
  for(int i = 0; i <= n; i++){
    delete [] dp[i];
  }
  delete [] dp;
  return ans;
}

bool subsetSum2(int *arr, int n, int k){
  bool **dp = new bool*[2];
  for(int i = 0; i <= 1; i++){
    dp[i] = new bool[k+1];
  }
  dp[0][0] = true;
  for(int j = 1; j <= k; j++){
    dp[0][j] = false;
  }
  int flag = 1;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= k; j++){
      if(arr[i-1] <= j){
        dp[flag][j] = dp[flag^1][j] || dp[flag^1][j-arr[i-1]];
        continue;
      }
      dp[flag][j] = dp[flag^1][j];
    }
    flag ^= 1;
  }
  bool ans = dp[flag^1][k];
  for(int i = 0; i <= 1; i++){
    delete [] dp[i];
  }
  delete [] dp;
  return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }
    cin >> k;
    cout << (subsetSum2(arr,n,k) ? "Yes" : "No") << endl;
    delete [] arr;
  }
  return 0;
}
