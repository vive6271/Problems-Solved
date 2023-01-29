#include<iostream>
using namespace std;
typedef long long ll;
bool check(ll n, ll k){
  ll ans = 0, curr = n, sh = 0;
  while(curr > 0){
    if(curr < k){
      sh += curr;
      break;
    }
    sh += k;
    curr -= k;
    curr -= curr/10;
  }
  return (sh >= (n+1)/2);
}

int main(){
  int t;
  cin >> t;
  while(t--){
    ll n;
    cin >> n;
    ll start = 1, end = n, mid, ans = 0;
    while(start <= end){
      mid = (start+end)/2;
      if(check(n,mid)){
        end = mid-1;
        ans = mid;
      }else{
        start = mid+1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
