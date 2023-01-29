#include<iostream>
using namespace std;
typedef long long int ll;

int factorial(ll n, ll m){
  ll ans = 1;
  for(int i = 2; i <= n; i++){
    ans = (ans * i) % m;
  }
  return (int) (ans % m);
}

int main(){
  int t;
  cin >> t;
  while(t--){
    ll n, m;
    cin >> n >> m;
    if(n < m){
      cout << factorial(n,m) << endl;
    }else if((n/m) % 2 == 1){
      int ans = (ll ((m-1) * factorial(n%m,m))) % m;
      cout << ans << endl;
    }else{
      cout << factorial(n%m, m) << endl;
    }
  }
  return 0;
}
