#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, w;
    cin >> n >> w;
    pair<ll,ll> *arr = new pair<ll,ll>[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i].first;
    }
    for(int i = 0; i < n; i++){
      cin >> arr[i].second;
    }
    sort(arr,arr+n);
    ll ***dp = new ll**[2];
    for(int i = 0; i < 2; i++){
      dp[i] = new ll*[n+1];
      for(int j = 0; j <= n; j++){
        dp[i][j] = new ll[w+1];
        for(int k = 0; k <= w; k++){
          dp[i][j][k] = 0;
        }
      }
    }

    int primes[11] = {1,2,3,5,7,11,13,17,19,23,29};
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= w; j++){
        dp[0][i][j] = dp[0][i-1][j];
        if(j >= arr[i-1].second){
          dp[0][i][j] = max(dp[0][i][j], dp[0][i-1][j-arr[i-1].second] + arr[i-1].first);
        }
      }
    }
    for(int p = 1; p <= 10; p++){
      int flag = p % 2;
      for(int i = 1; i <= n; i++){
        for(int j = 1; j <= w; j++){
          dp[flag][i][j] = dp[flag][i-1][j];
          if(j >= arr[i-1].second){
            dp[flag][i][j] = max(dp[flag][i][j], max((dp[flag][i-1][j-arr[i-1].second] + arr[i-1].first),(dp[flag^1][i-1][j-arr[i-1].second] + arr[i-1].first * primes[p])));
          }
        }
      }
    }

    cout << dp[0][n][w] << endl;
    for(int i = 0; i < 2; i++){
      for(int j = 0; j <= n; j++){
        delete [] dp[i][j];
      }
      delete [] dp[i];
    }
    delete [] dp;
  }
  return 0;
}
