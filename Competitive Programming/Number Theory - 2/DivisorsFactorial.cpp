#include<iostream>
using namespace std;
typedef long long ll;
int MOD = 1000000000+7;

int divisorFactorial(int n){
  bool *prime = new bool[n+1];
  for(int i = 0; i <= n; i++){
    prime[i] = true;
  }
  prime[0] = false;
  prime[1] = false;

  for(int i = 2; i*i <= n; i++){
    if(prime[i]){
      for(int j = i*i; j <= n; j += i){
        prime[j] = false;
      }
    }
  }
  ll ans = 1;
  for(int i = 2; i <= n; i++){
    if(prime[i]){
      ll sum = 0;
      for(int j = i; j <= n; j *= i){
        sum = ((ll) sum + (n/j)) % MOD;
      }
      ans = ((ll) ans * (sum+1)) % MOD;
    }
  }
  return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    cout << divisorFactorial(n) << endl;
  }
  return 0;
}
