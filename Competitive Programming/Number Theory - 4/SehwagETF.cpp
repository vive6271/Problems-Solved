#include<bits/stdc++.h>
using namespace std;
#define N 1000001
#define M 100001
#define endl '\n'
bool isPrime[N];
int euler[M], primeFactor[M];
vector<int> x;

void sieve(){
  for(int i = 2; i < N; i++){
    isPrime[i] = true;
  }
  isPrime[0] = false;
  isPrime[1] = false;
  for(int i = 2; i*i < N; i++){
    if(isPrime[i]){
      for(int j = i*i; j < N; j += i){
        isPrime[j] = false;
      }
    }
  }
  for(int i = 2; i < N; i++){
    if(isPrime[i]){
      x.push_back(i);
    }
  }
}

double sehwagETF(int l, int r, int k){
  for(int i = l; i <= r; i++){
    euler[i-l] = i;
    primeFactor[i-l] = i;
  }
  for(int i = 0; x[i]*x[i] <= r; i++){
    int nextmulti = l / x[i] * x[i];
    while(nextmulti < l){
      nextmulti += x[i];
    }

    for(int j = nextmulti; j <= r; j += x[i]){
      while(primeFactor[j-l] % x[i] == 0){
        primeFactor[j-l] /= x[i];
      }
      euler[j-l] -= euler[j-l] / x[i];
    }
  }
  for(int i = l; i <= r; i++){
    if(primeFactor[i-l] > 1){
      euler[i-l] -= euler[i-l] / primeFactor[i-l];
    }
    primeFactor[i-l] = 1;
  }
  int c = 0;
  for(int i = l; i <= r; i++){
    if(euler[i-l] % k ==  0){
      c++;
    }
  }
  double ans = c;
  ans /= (r-l+1);
  return ans;
}
int main(){
  int t;
  cin >> t;
  sieve();
  while(t--){
    int l, r, k;
    cin >> l >> r >> k;
    if(k == 1){
      cout << fixed << setprecision(6) << 1 << endl;
      continue;
    }
    double ans = sehwagETF(l,r,k);
    cout << fixed << setprecision(6) << ans << endl;
  }
  return 0;
}
