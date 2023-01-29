#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll angryChild(int *arr, int n, int k){
  sort(arr,arr+n);
  ll *sum = new ll[n+1];
  ll curr = 0, ans = 0;
  sum[0] = 0;
  for(int i = 0; i < n; i++){
    sum[i+1] = sum[i] + arr[i];
  }

  for(int i = 0; i < k; i++){
    curr += (1ll * i *arr[i] - sum[i]);
  }
  ans = curr;
  for(int i = k; i < n; i++){
    curr = curr - 2ll * (sum[i] - sum[i-k+1]) + 1ll * (k-1) *  (arr[i]+arr[i-k]);
    ans = min(ans,curr);
  }
  delete [] sum;
  return ans;
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }
    cout << angryChild(arr,n,k) << endl;
    delete [] arr;
  }
  return 0;
}
