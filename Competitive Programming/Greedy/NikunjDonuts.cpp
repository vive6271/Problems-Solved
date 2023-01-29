#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    sort(arr, arr+n, greater<int>());
    ll ans = 0;
    for(int i = 0; i < n; i++){
      ans += (ll (arr[i] * pow(2,i)));
    }
    cout << ans << endl;
    delete [] arr;
  }
  return 0;
}
