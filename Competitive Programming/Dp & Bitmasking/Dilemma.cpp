#include<bits/stdc++.h>
using namespace std;

int findTouches(vector<string> &v, int mask, int pos, int **dp){
  if((mask & (mask-1)) == 0){
    return 0;
  }
  if(pos < 0){
    return 10000;
  }
  if(dp[pos][mask] != INT_MAX){
    return dp[pos][mask];
  }
  int touch = 0, newMask1 = 0, newMask2 = 0;
  for(int i = 0; i < v.size(); i++){
    if(mask & (1<<i)){
      if(v[i][pos] == '0'){
        newMask1 |= (1<<i);
      }else{
        newMask2 |= (1<<i);
      }
      touch++;
    }
  }
  int a = findTouches(v, newMask1, pos-1, dp) + findTouches(v, newMask2, pos-1, dp) + touch;
  int b = findTouches(v, mask, pos-1, dp);
  dp[pos][mask] = min(a,b);
  return dp[pos][mask];
}

int minTouchesRequired(vector<string> v, int n){
  int **dp = new int*[v[0].size()];
  for(int i = 0; i < v[0].size(); i++){
    dp[i] = new int[1<<(n+1)];
    for(int j = 0; j < (1<<(n+1)); j++){
      dp[i][j] = INT_MAX;
    }
  }
  int ans = findTouches(v, (1<<n)-1, v[0].size()-1, dp);
  for(int i = 0; i < v[0].size(); i++){
    delete [] dp[i];
  }
  delete [] dp;
  return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<string> v;
    for(int i = 0; i < n; i++){
      string str;
      cin >> str;
      v.push_back(str);
    }
    cout << minTouchesRequired(v,n) << endl;
  }
  return 0;
}
