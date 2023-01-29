#include<iostream>
using namespace std;
typedef long long int ll;
int MOD = 1000000000+7;

void multiply(ll A[2][2], ll M[2][2]){
  ll Value1 = ((ll (A[0][0] * M[0][0]) % MOD) + (ll (A[0][1] * M[1][0]) % MOD)) % MOD;
  ll Value2 = ((ll (A[0][0] * M[1][0]) % MOD) + (ll (A[0][1] * M[1][1]) % MOD)) % MOD;
  ll Value3 = ((ll (A[1][0] * M[0][0]) % MOD) + (ll (A[1][1] * M[1][0]) % MOD)) % MOD;
  ll Value4 = ((ll (A[1][0] * M[0][1]) % MOD) + (ll (A[1][1] * M[1][1]) % MOD)) % MOD;


  A[0][0] = Value1, A[0][1] = Value2, A[1][0] = Value3, A[1][1] = Value4;
}

void power(ll A[2][2], ll n){
  if(n == 0 || n == 1){
    return;
  }
  power(A,n/2);

  multiply(A,A);
  if(n%2 != 0){
    ll M[2][2] = {{1,1},{1,0}};
    multiply(A,M);
  }
}

int fibonacci(ll n){
  if(n == 0){
    return 0;
  }
  ll A[2][2] = {{1,1},{1,0}};
  power(A,n-1);
  return A[0][0];
}

int main(){
  int t;
  cin >> t;
  while(t--){
    ll n, m;
    cin >> n >> m;
    int sum = ((fibonacci(m+2) % MOD - fibonacci(n+1) % MOD) + MOD) % MOD;
    cout << sum << endl;
  }
  return 0;
}
