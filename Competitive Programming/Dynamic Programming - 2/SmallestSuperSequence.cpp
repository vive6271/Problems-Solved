#include<iostream>
using namespace std;

int superSequence(string s, string t){
  int n = s.length();
  int m = t.length();
  int **dp = new int*[n+1];
  for(int i = 0; i <= n; i++){
    dp[i] = new int[m+1];
  }
  dp[n][m] = 0;

  for(int i = n-1; i >= 0; i--){
    dp[i][m] = dp[i+1][m] + 1;
  }
  for(int j = m-1; j >= 0; j--){
    dp[n][j] = dp[n][j+1] + 1;
  }

  for(int i = n-1; i >= 0; i--){
    for(int j = m-1; j >= 0; j--){
      if(s[i] == t[j]){
        dp[i][j] = 1 + dp[i+1][j+1];
      }else{
        dp[i][j] = 1 + min(dp[i+1][j],dp[i][j+1]);
      }
    }
  }
  int ans = dp[0][0];
  for(int i = 0; i <= n; i++){
    delete [] dp[i];
  }
  delete [] dp;
  return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    string s, t;
    cin >> s >> t;
    cout << superSequence(s,t) << endl;
  }
  return 0;
}
