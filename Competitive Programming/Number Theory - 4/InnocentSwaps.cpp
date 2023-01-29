#include<iostream>
using namespace std;
#define endl '\n'
#define ll long long int
#define N 1000001
#define MOD 1000000007
ll fact[N];

void factorial(){
  fact[0] = 1;
  for(int i = 1; i < N; i++){
    fact[i] = ((fact[i-1] * i)) % MOD;
  }
}

ll modularExponentiation(ll a, ll b){
  ll ans = 1;
  while(b > 0){
    if(b&1){
      ans = (ans*a) % MOD;
    }
    a = (a*a) % MOD;
    b >>= 1;
  }
  return ans;
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  factorial();

  int t;
  cin >> t;
  while(t--){
    ll n, k, ans;
    cin >> n >> k;
    ans = modularExponentiation(2,k) % MOD;
    ans = (ans * fact[n]) % MOD;
    ans = (ans * modularExponentiation(fact[k], MOD-2)) % MOD;
    ans = (ans * modularExponentiation(fact[n-k], MOD-2)) % MOD;
    cout << ans << endl;
  }
  return 0;
}
