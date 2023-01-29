#include<iostream>
using namespace std;
int MOD = 1000000000+7;
typedef long long ll;

int countString(string s){
  int n = s.size();
  ll req = 0, dp[n+1], arr[n+1], ans = 0;
  for(int i = 0; i < n; i++){
    arr[i] = ('Z' - s[i]);
  }
  dp[n-1] = arr[n-1];
  for(int i = n-2; i >= 0; i--){
    req = (arr[i+1] + (26ll * req) % MOD) % MOD;
    dp[i] = (arr[i] + (arr[i] *  req) % MOD) % MOD;
  }
  for(int i = 0; i < n; i++){
    ans = (ans + dp[i]) % MOD;
  }
  return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    cout << countString(s) << endl;
  }
  return 0;
}
