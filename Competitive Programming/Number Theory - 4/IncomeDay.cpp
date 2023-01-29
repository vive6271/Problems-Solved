#include<iostream>
using namespace std;
typedef long long int ll;
int MOD1 = 1000000000+7;
int MOD2 = 1000000000+6;

//Fibonacci
void multiply(ll A[2][2], ll M[2][2]){
  ll Value1 = ((ll (A[0][0] * M[0][0]) % MOD2) + (ll (A[0][1] * M[1][0]) % MOD2)) % MOD2;
  ll Value2 = ((ll (A[0][0] * M[1][0]) % MOD2) + (ll (A[0][1] * M[1][1]) % MOD2)) % MOD2;
  ll Value3 = ((ll (A[1][0] * M[0][0]) % MOD2) + (ll (A[1][1] * M[1][0]) % MOD2)) % MOD2;
  ll Value4 = ((ll (A[1][0] * M[0][1]) % MOD2) + (ll (A[1][1] * M[1][1]) % MOD2)) % MOD2;

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

ll fib(ll n){
  if(n == 0){
    return 0;
  }
  ll A[2][2] = {{1,1},{1,0}};
  power(A,n-1);
  return A[0][0];
}

//Power
ll power(ll a, ll b){
  ll ans = 1;
  while(b > 0){
    if(b&1){
      ans = (ans*a) % MOD1;
    }
    a = (a*a) % MOD1;
    b /= 2;
  }
  return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    ll a, b, n, x, y, ans;
    cin >> a >> b >> n;
    if(n == 0){
      cout << a << endl;
    }else if(n == 1){
      cout << b << endl;
    }else{
      x = fib(n-1);
      y = fib(n);
      ans = (power(a+1,x) * power(b+1,y)) - 1;
      ans = (ans + MOD1) % MOD1;
      cout << ans << endl;
    }
  }
  return 0;
}
