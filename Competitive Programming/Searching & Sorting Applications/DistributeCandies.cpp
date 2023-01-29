#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


bool isPossible(ll *arr, int n, int x, int k){
  for(int i = 0; i < n; i++){
    if(arr[i] >= x){
      k -= arr[i] / x;
    }
    if(k <= 0){
      return true;
    }
  }
  return false;
}

ll distributeCandies(ll *arr, int n, int k){
  ll maxCount = 0;
  sort(arr,arr+n);
  int start = 0, end = arr[n-1], mid = 0;
  while(start <= end){
    mid = (start+end) / 2;
    if(isPossible(arr,n,mid,k)){
      maxCount = mid;
      start = mid+1;
    }else{
      end = mid-1;
    }
  }
  return maxCount;
}

int main(){
    // write your code
    int t;
    cin >> t;
    while(t--){
      int n, k;
      cin >> n >> k;
      ll *arr = new ll[n];
      for(int i = 0; i < n; i++){
        cin >> arr[i];
      }
      cout << distributeCandies(arr,n,k) << endl;
    }
    return 0;
}
