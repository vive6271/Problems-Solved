#include<iostream>
using namespace std;
int MOD = 1000000000+7;

/* Note :- Try to fill all helpArr 100*100*2 first and return only ans for give input
int bitCount(int n, int k, int first, int ***helpArr){
  if(n == 1){
    if(k == 0){
      return 1;
    }
    return 0;
  }
  if(k < 0){
    return 0;
  }
  if(helpArr[n][k][first] != -1){
    return helpArr[n][k][first];
  }
  int ans;
  if(first == 1){
    ans = ((long long) bitCount(n-1,k-1,1,helpArr) + bitCount(n-1,k,0,helpArr)) % MOD;
  }else{
    ans = ((long long )bitCount(n-1,k,1,helpArr) + bitCount(n-1,k,0,helpArr)) % MOD;
  }
  helpArr[n][k][first] = ans;
  return ans;
}

int adjacentBit(int n, int k){
  int ***helpArr = new int**[n+1];
  for(int i = 0; i <= n; i++){
    helpArr[i] = new int*[k+1];
    for(int j = 0; j <= k; j++){
      helpArr[i][j] = new int[2];
      for(int l = 0; l < 2; l++){
        helpArr[i][j][l] = -1;
      }
    }
  }
  int ans = ((long long) bitCount(n,k,0,helpArr) + bitCount(n,k,1,helpArr)) % MOD;
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= k; j++){
      delete [] helpArr[i][j];
    }
    delete [] helpArr[i];
  }
  delete [] helpArr;
  return ans;
}
*/

void adjacentBit(int n, int k, int ***dp){
  dp[1][0][0] = 1;
  dp[1][0][1] = 1;
  for(int i = 2; i <= n; i++){
    dp[i][i-1][0] = 0;
    dp[i][i-1][1] = 1;
    dp[i][0][0] = ((long long) dp[i-1][0][0] + dp[i-1][0][1]) % MOD;
    dp[i][0][1] = dp[i-1][0][0];
  }

  for(int i = 2; i <= n; i++){
    for(int j = 1; j < i; j++){
      dp[i][j][1] = ((long long) dp[i-1][j-1][1] + dp[i-1][j][0]) % MOD;
      dp[i][j][0] = ((long long) dp[i-1][j][1] + dp[i-1][j][0]) % MOD;
    }
  }
}

int main(){
  int t;
  cin >> t;
  int ***dp = new int**[101];
  for(int i = 0; i <= 100; i++){
    dp[i] = new int*[101];
    for(int j = 0; j <= 100; j++){
      dp[i][j] = new int[2];
    }
  }
  adjacentBit(100, 100, dp);
  while(t--){
    int n, k;
    cin >> n >> k;
    if(n == 0 && k == 0){
      cout << 1 << endl;
    }else{
      int ans = ((long long) dp[n][k][0] + dp[n][k][1]) % MOD;
      cout << ans << endl;
    }
  }
  for(int i = 0; i <= 100; i++){
    for(int j = 0; j <= 100; j++){
      delete [] dp[i][j];
    }
    delete [] dp[i];
  }
  delete [] dp;
  return 0;
}
