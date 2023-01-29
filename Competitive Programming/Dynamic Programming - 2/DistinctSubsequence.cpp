#include<iostream>
#include<string>
using namespace std;
int MOD = 1000000000+7;

int subSequence(string str){
  int n = str.length();
  int *dp = new int[n+1];
  int prevIndices[26];
  for(int i = 0; i < 26; i++){
    prevIndices[i] = -1;
  }
  dp[0] = 1;
  for(int i = 1; i <= n; i++){
    dp[i] = ((long long) 2*dp[i-1]) % MOD;
    if(prevIndices[str[i-1]-65] != -1){
      dp[i] = ((long long)dp[i] - dp[prevIndices[str[i-1]-65]-1] + MOD) % MOD;
    }
    prevIndices[str[i-1]-65] = i;
  }
  int ans = dp[n];
  delete [] dp;
  return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    string str;
    cin >> str;
    cout << subSequence(str) << endl;
  }
  return 0;
}
