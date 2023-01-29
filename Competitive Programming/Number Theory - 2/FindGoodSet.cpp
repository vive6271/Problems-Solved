#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int MOD = 1000000000+7;

int goodSet(int *arr, int n){
  int size = arr[n-1];
  int *sieve = new int[size+1];
  int k = 0;
  for(int i = 0; i <= size; i++){
    if(arr[k] == i){
      sieve[i] = 1;
      k++;
    }else{
      sieve[i] = 0;
    }
  }

  for(int i = 1; i <= size; i++){
    if(sieve[i] != 0){
      for(int j = 2*i; j <= size; j += i){
        if(sieve[j]){
          sieve[j] = ((sieve[j] % MOD) + (sieve[i] % MOD)) % MOD;
        }
      }
    }
  }
  int sum = 0;
  for(int i = 0; i <= size; i++){
    sum = ((sum % MOD) + (sieve[i] % MOD)) % MOD;
  }
  delete [] sieve;
  return sum;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }
    sort(arr,arr+n);
    cout << goodSet(arr, n) << endl;
    delete [] arr;
  }
  return 0; 
}
