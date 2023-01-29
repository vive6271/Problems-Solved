#include<iostream>
using namespace std;
#define int long long int

int checkCandy(int **like, int n){
  int *dp = new int[1<<n];
  for(int i = 0; i < (1<<n); i++){
    dp[i] = 0;
  }
  dp[0] = 1;
  for(int mask = 0; mask < ((1<<n)-1); mask++){
    int tmp = mask;
    int k = 0;
    while(tmp > 0){
      if((tmp%2) == 1){
        k++;
      }
      tmp = tmp/2;
    }
    for(int j = 0; j < n; j++){
      if(!(mask & (1<<j)) && like[k][j] == 1){
        dp[mask | (1<<j)] += dp[mask];
      }
    }
  }
  int ans = dp[(1<<n)-1];
  delete [] dp;
  return ans;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int **arr = new int*[n];
    for(int i = 0; i < n; i++){
      arr[i] = new int[n];
      for(int j = 0; j < n; j++){
        cin >> arr[i][j];
      }
    }
    cout << checkCandy(arr,n) << endl;
    //delete
    for(int i = 0; i < n; i++){
      delete [] arr[i];
    }
    delete [] arr;
  }
  return 0;
}
