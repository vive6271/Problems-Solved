#include<iostream>
using namespace std;
#define int long long int

int ghost(int n){
  int *dp = new int[1<<n];
  for(int i = 0; i < (1<<n); i++){
    dp[i] = 0;
  }
  dp[0] = 1;
  for(int mask = 0; mask < ((1<<n)-1); mask++){
    for(int i = 0; i < n; i++){
      if((mask & (1<<i)) == 0){
        bool flag = false;
        for(int j = 0; j < n; j++){
          if((mask & (1<<j)) && ((i+1) & (j+1)) == (i+1)){
            flag = true;
            break;
          }
        }
        if(flag == false){
          dp[mask | (1<<i)] += dp[mask];
        }
      }
    }
  }
  int ans = dp[(1<<n)-1];
  delete [] dp;
  return ans;
}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  cout << ghost(n) << endl;
  return 0;
}
