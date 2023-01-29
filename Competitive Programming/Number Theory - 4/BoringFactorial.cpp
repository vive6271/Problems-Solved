#include<iostream>
using namespace std;
typedef long long int ll;

ll power(ll a, ll b, ll p){
  ll ans = 1;
  while(b > 0){
    if(b&1){
      ans = (ans*a) % p;
    }
    a = (a*a) % p;
    b /= 2;
  }
  return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    ll n, p, fact = 1;
    cin >> n >> p;
    if(n >= p){
      cout << 0 << endl;
      continue;
    }
    for(ll i = n+1; i <= p-1; i++){
      fact = (fact*i) % p;
      if(fact == 0){
        break;
      }
    }
    int ans = (p-power(fact, p-2, p));
    cout << ans << endl;
  }
  return 0;
}
