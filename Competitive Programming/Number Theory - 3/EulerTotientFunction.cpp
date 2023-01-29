#include<iostream>
#include<cmath>
using namespace std;

int totientFunction(int n){
  int sieve[n+1];
  for(int i = 0; i <= n; i++){
    sieve[i] = i;
  }

  for(int i = 2; i <= n; i++){
    if(sieve[i] == i){
      sieve[i] = i-1;
      double a = double (i-1)/i;
      for(int j = 2*i; j <= n; j += i){
        sieve[j] = round(double (a * sieve[j]));
      }
    }
  }
  return sieve[n];
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    cout << totientFunction(n) << endl;
  }
  return 0;
}
