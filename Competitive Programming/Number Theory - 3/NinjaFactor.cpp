#include<iostream>
#include<vector>
using namespace std;
typedef long long int ll;

int main(){
  ll n, q;
  cin >> n >> q;
  vector<ll> dp(n+1, 0);

  for(ll i = 1; i <= n; i++){
    ll a;
    cin >> a;
    if(a == 3 || a == 4 || a == 6){
      dp[i] = 1;
    }
    dp[i] += dp[i-1];
  }
  while(q--){
    ll l, r;
    cin >> l >> r;
    cout << dp[r] - dp[l-1] << endl;
  }
  return 0;
}
