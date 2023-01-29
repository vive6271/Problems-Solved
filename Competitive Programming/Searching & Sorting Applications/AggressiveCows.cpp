#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int aggressiveCows(ll *arr, int n, int x){
  int ans = 0;
  sort(arr, arr+n);
  int start = 0, end = arr[n-1]-1, mid = 0;
  while(start <= end){
    mid = (start+end) / 2;
    ll prev = arr[0];
    ll count = x-1;
    for(int i = 1; i < n; i++){
      if(prev + mid <= arr[i]){
        prev = arr[i];
        count--;
      }
      if(count == 0){
        break;
      }
    }
    if(count == 0){
      ans = mid;
      start = mid+1;
    }else{
      end = mid-1;
    }
  }
  return ans;
}

int main(){
    // write your code
    int t;
    cin >>t;
    while(t--){
      int n, x;
      cin >> n >> x;
      ll *arr = new ll[n];
      for(int i = 0; i < n; i++){
        cin >> arr[i];
      }
      cout << aggressiveCows(arr, n, x) << endl;
      delete [] arr;
    }
    return 0;
}
