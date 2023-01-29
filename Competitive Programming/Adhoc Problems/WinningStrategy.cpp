#include<bits/stdc++.h>
using namespace std;

bool isValid(int *arr, int n){
  for(int i = 0; i < n; i++){
    if(((arr[i] - (i+1)) > 2) || (arr[i] - (i+1)) < -2){
      return false;
    }
  }
  return true;
}

int32_t main(){

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }

    if(isValid(arr,n)){
      int minSwap = 0, l = 2;
      while(l--){
        for(int i = 0; i < n-1; i++){
          if(arr[i] > arr[i+1]){
            swap(arr[i],arr[i+1]);
            minSwap++;
          }
        }
      }
      cout << "YES\n" << minSwap << '\n';
    }else{
      cout << "NO" << '\n';
    }
  }
  return 0 ;
}
