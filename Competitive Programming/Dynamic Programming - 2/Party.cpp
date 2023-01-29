#include<iostream>
#include<climits>
using namespace std;

pair<int,int> party(int *fee, int *fun, int n, int budget){
  pair<int,int> **dp = new pair<int,int>*[n+1];
  for(int i = 0; i <= n; i++){
    dp[i] = new pair<int,int>[budget+1];
  }
  for(int i = 0; i <= n; i++){
    dp[i][0].first = 0;
    dp[i][0].second = 0;
  }
  for(int j = 1; j <= budget; j++){
    dp[0][j].first = 0;
    dp[0][j].second = 0;
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= budget; j++){
      pair<int,int> a = dp[i-1][j];
      pair<int,int> b;
      b.second = INT_MIN;
      if(fee[i-1] <= j){
        pair<int,int> tmp = dp[i-1][j-fee[i-1]];
        b.first = fee[i-1] + tmp.first;
        b.second = fun[i-1] + tmp.second;
      }
      if(a.second > b.second){
        dp[i][j] = a;
      }else{
        dp[i][j] = b;
      }
    }
  }
  pair<int,int> ans = dp[n][budget];
  for(int i = 0; i <= n; i++){
    delete [] dp[i];
  }
  delete [] dp;
  return ans;
}

int main(){
  int n, budget;
  cin >> n;
  int *fee = new int[n];
  int *fun = new int[n];

  for(int i = 0; i < n; i++){
    cin >> fee[i];
  }
  for(int i = 0; i < n; i++){
    cin >> fun[i];
  }

  cin >> budget;
  pair<int,int> ans = party(fee,fun,n,budget);
  cout << ans.first << " " << ans.second << endl;
  delete [] fee;
  delete [] fun;
  return 0;
}
