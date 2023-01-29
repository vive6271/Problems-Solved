#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    // write your code
    int n, q;
    cin >> n;
    ll *arr = new ll[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }
    ll *prefixSum = new ll[n];
    prefixSum[0] = arr[0];
    for(int i = 1; i < n; i++){
      prefixSum[i] = prefixSum[i-1] + arr[i];
    }

    cin >> q;
    while(q--){
      int x, index = 0;
      cin >> x;
      int start = 0, end = n-1, mid = 0;
      while(start <= end){
        mid = (start+end) / 2;
        if(prefixSum[mid] <= x){
          index = mid;
          start = mid+1;
        }else{
          end = mid-1;
        }
      }
      ll leftMoney = x - prefixSum[index];
      cout << index+1 << " " << leftMoney << endl;
    }
    return 0;
}
