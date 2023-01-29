#include<iostream>
#include<vector>
using namespace std;
#define N 100001
typedef long long ll;

vector<int> *sieve(){
  bool isPrime[N];
  for(int i = 0; i < N; i++){
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
  vector<int> *primes = new vector<int>();
  primes -> push_back(2);
  for(int i = 3; i < N; i += 2){
    if(isPrime[i]){
      primes -> push_back(i);
    }
  }
  return primes;
}

void printPrimes(ll l, ll r, vector<int>* &primes){
  bool isPrime[r-l+1];

  for(int i = 0; i <= r-l+1; i++){
    isPrime[i] = true;
  }
  for(int i = 0; (ll (primes->at(i) * primes->at(i))) <= r; i++){
    int currPrime = primes -> at(i);
    //Just smaller or equal value to l
    ll base = (l/(currPrime)) * (currPrime);
    if(base < l){
      base += currPrime;
    }

    //Mark all multiple within L to R as false
    for(ll j = base; j <= r; j += currPrime){
      isPrime[j-l] = false;
    }

    //There may be a case where base is itself a prime num.
    if(base == currPrime){
      isPrime[base-l] = true;
    }
  }

  for(int i = 0; i <= r-l; i++){
    if(isPrime[i] && (i+l) != 1){
      cout << i+l << " ";
    }
  }
  cout << endl;
  return;
}
int main(){
  int t;
  cin >> t;
  vector<int> *primes = sieve();
  while(t--){
    ll l, r;
    cin >> l >> r;
    printPrimes(l,r,primes);
  }
  return 0;
}
