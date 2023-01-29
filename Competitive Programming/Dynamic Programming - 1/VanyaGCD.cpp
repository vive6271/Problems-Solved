#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int findGCD(int *arr, int n){
  int **output = new int*[n];
  for(int i = 0; i < n; i++){
    output[i] = new int[101];
    for(int j = 0; j <= 100; j++){
      output[i][j] = 0;
    }
  }
  int maxVal = INT_MIN;
  for(int i = 0; i < n; i++){
    output[i][arr[i]]++;
    maxVal = max(arr[i],maxVal);
  }
  for(int i = 1; i < n; i++){
    for(int j = 0; j < i; j++){
      if(arr[j] < arr[i]){
        for(int k = 1; k <= maxVal; k++){
          int x = __gcd(k,arr[i]);
          output[i][x] = ((long) output[i][x]+output[j][k]) % MOD;
        }
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
    ans = ((long) ans+output[i][1]) % MOD;
  }
  for(int i = 0; i < n; i++){
    delete [] output[i];
  }
  delete [] output;
  return ans;
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
    cout << findGCD(arr,n) << endl;
  }
  return 0;
}
