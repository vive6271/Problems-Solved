#include<iostream>
using namespace std;
int MOD = 1000000000+7;

int maker(string a, string b, string c, int ***dp){
  int m = a.length(), n = b.length(), o = c.length();
  if(o == 0){
    return 1;
  }
  if(m == 0 && n == 0){
    return 0;
  }
  if(dp[m][n][o] != -1){
    return dp[m][n][o];
  }
  int ans = 0;
  for(int i = 0; i < m; i++){
    if(a[i] == c[0]){
      ans = ((long long) ans + maker(a.substr(i+1), b, c.substr(1), dp)) % MOD;
    }
  }
  for(int i = 0; i < n; i++){
    if(b[i] == c[0]){
      ans = ((long long) ans + maker(a, b.substr(i+1), c.substr(1), dp)) % MOD;
    }
  }
  dp[m][n][o] = ans;
  return ans;
}

int stringMaker(string a, string b, string c){
  int m = a.length(), n = b.length(), o = c.length();
  int ***dp = new int**[m+1];
  for(int i = 0; i <= m; i++){
    dp[i] = new int*[n+1];
    for(int j = 0; j <= n; j++){
      dp[i][j] = new  int[o+1];
      for(int k = 0; k <= o; k++){
        dp[i][j][k] = -1;
      }
    }
  }
  int ans = maker(a,b,c,dp);
  for(int i = 0; i <= m; i++){
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
    string a, b, c;
    cin >> a >> b >> c;
    cout << stringMaker(a,b,c) << endl;
  }
  return 0;
}
