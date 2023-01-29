#include<bits/stdc++.h>
using namespace std;

int solve(pair<int,int> *arr, int n, int w){
  int prime[10] = {2,3,5,7,11,13,17,19,23,29};
  int ***dp = new int**[2];
  for(int i = 0; i < 2; i++){
    dp[i] = new int*[n+1];
    for(int j = 0; j <= n; j++){
      dp[i][j] = new int[w+1];
      for(int k = 0; k <= w; k++){
        dp[i][j][k] = 0;
      }
    }
  }
  sort(arr,arr+n);
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= w; j++){
      int a = dp[0][i-1][j];
      int b = INT_MIN;
      if(j >= arr[i-1].second){
        b = dp[0][i-1][j-arr[i-1].second] + arr[i-1].first;
      }
      dp[0][i][j] = max(a,b);
    }
  }
  int flag = 1;
  for(int p = 0; p < 10; p++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= w; j++){
        int a = dp[flag][i-1][j];
        int b = INT_MIN;
        if(j >= arr[i-1].second){
          b = max((dp[flag][i-1][j-arr[i-1].second] + arr[i-1].first),(dp[flag^1][i-1][j-arr[i-1].second] + arr[i-1].first * prime[p]));
        }
        dp[flag][i][j] = max(a,b);
      }
    }
    flag ^= 1;
  }

  int ans = dp[flag^1][n][w];
  for(int i = 0; i < 2; i++){
    for(int j = 0; j <= n; j++){
      delete [] dp[i][j];
    }
    delete [] dp[i];
  }
  delete [] dp;
  return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, w;
    cin >> n >> w;
    pair<int,int> *arr = new pair<int,int>[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i].first;
    }
    for(int i = 0; i < n; i++){
      cin >> arr[i].second;
    }
    cout << solve(arr,n,w) << endl;
    delete [] arr;
  }
  return 0;
}
