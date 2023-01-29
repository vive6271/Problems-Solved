#include<bits/stdc++.h>
using namespace std;

int solve(int *arr, int n){
  sort(arr, arr+n);
  int curr = 1, ans = 0;
  for(int i = 0; i < n; i++){
    if(curr == arr[i]){
      ans++;
      curr = 0;
    }
    curr++;
  }
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
    cout << solve(arr, n) << endl;
    delete [] arr;
  }
  return 0;
}
