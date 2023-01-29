#include<iostream>
using namespace std;

int editDistance(string str1, string str2){
  int m = str1.length();
  int n = str2.length();

  int **dp = new int*[m+1];
  for(int i = 0; i <= m; i++){
    dp[i] = new int[n+1];
  }

  for(int i = 0; i <= m; i++){
    dp[i][0] = i;
  }
  for(int j = 1; j <= n; j++){
    dp[0][j] = j;
  }

  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){
      if(str1[m-i] == str2[n-j]){
        dp[i][j] = dp[i-1][j-1];
      }else{
        dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
      }
    }
  }
  int ans = dp[m][n];
  for(int i = 0; i <= m; i++){
    delete [] dp[i];
  }
  delete [] dp;
  return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    string str1, str2;
    cin >> str1 >> str2;
    cout << editDistance(str1,str2) << endl;
  }
  return 0;
}
