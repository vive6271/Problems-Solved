#include<iostream>
using namespace std;
#define int long long

int mod = 1000000000 + 7;

int stairCase(int n){
  int *arr = new int[n+1];
  arr[0] = 1;
  arr[1] = 1;
  arr[2] = 2;
  for(int i = 3; i <= n; i++){
    arr[i] = (arr[i-3] + arr[i-2] + arr[i-1]) % mod;
  }
  int ans = arr[n];
  delete [] arr;
  return ans;
}

int32_t main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    cout << stairCase(n) << endl;
  }
  return 0;
}
