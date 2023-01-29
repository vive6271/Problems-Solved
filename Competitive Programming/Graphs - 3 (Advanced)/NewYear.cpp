#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, q, x;
    cin >> n;
    int *arr = new int[n-1];
    for(int i = 0; i < n-1; i++){
      cin >> arr[i];
    }
    cin >> q;
    bool *isPossible = new bool[n]();
    int i = 1;
    while(i < n){
      isPossible[i-1] = true;
      i = i + arr[i-1];
    }
    if(i == n){
      isPossible[n-1] = true;
    }
    for(int i = 0; i < q; i++){
      cin >> x;
      if(isPossible[x-1]){
        cout << "YES" << endl;
      }else{
        cout << "NO" << endl;
      }
    }
    delete [] arr;
    delete [] isPossible;
  }
  return 0;
}
