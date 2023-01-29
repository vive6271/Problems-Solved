#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        string str1, str2;
        cin >> str1 >> str2;
        int n = str1.size(), m = str2.size(), k;
        cin >> k;
        int dp[n + 1][m + 1][101];
        int lcs[n + 1][m + 1];
        memset(dp, 0, sizeof dp);
        memset(lcs, 0, sizeof lcs);
        for (int i = 0; i <= n; i++){
            for (int j = 0; j <= m; j++){
                if (i == 0 || j == 0){
                    for (int z = 0; z <= k; z++)
                        dp[i][j][z] = 0;
                    lcs[i][j] = 0;
                }else if (str1[i - 1] == str2[j - 1]){
                    lcs[i][j] = 1 + lcs[i - 1][j - 1];
                    for (int z = 0; z <= lcs[i][j]; z++){
                        if (z == 0)
                            dp[i][j][z] = 0;
                        else
                            dp[i][j][z] = max(dp[i - 1][j - 1][z -1] + (int)str1[i - 1], dp[i - 1][j - 1][z]);
                    }
                }else{
                    lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
                    for (int z = 0; z <= lcs[i][j]; z++){
                        dp[i][j][z] = max(dp[i - 1][j][z], dp[i][j - 1][z]);
                    }
                }
            }
        }
        if (lcs[n][m] < k)
            cout << "0" << endl;
        else
            cout << dp[n][m][k] << endl;
    }
    return 0;
}

/*
int balikaVadhu(string s1, int n, string s2, int m, int k, int ***helpArr){
  if(k == 0){
    return 0;
  }
  if(n == 0 || m == 0 || n < k ||  m < k){
    return 0;
  }
  if(helpArr[n][m][k] != -1){
    return helpArr[n][m][k];
  }
  int ans;
  if(s1[0] != s2[0]){
    ans = max(balikaVadhu(s1.substr(1), n-1, s2, m, k, helpArr), balikaVadhu(s1, n, s2.substr(1), m-1, k, helpArr));
  }else{
    int a = balikaVadhu(s1.substr(1), n-1, s2.substr(1), m-1, k-1, helpArr);
    if(a == 0 && k > 1){
      ans = 0;
    }else{
      ans = max(s1[0]+a, max(balikaVadhu(s1.substr(1), n-1, s2, m, k, helpArr), balikaVadhu(s1, n, s2.substr(1), m-1, k, helpArr)));
    }
  }
  helpArr[n][m][k] = ans;
  return ans;
}

  int solve(string s1, string s2, int k){
  int n = s1.length();
  int m = s2.length();
  int ***helpArr = new int**[n+1];
  for(int i = 0; i <= n; i++){
    helpArr[i] = new int*[m+1];
    for(int j = 0; j <= m; j++){
      helpArr[i][j] = new int[k+1];
      for(int l = 0; l <= k; l++){
        helpArr[i][j][l] = -1;
      }
    }
  }
  int ans = balikaVadhu(s1, n, s2, m, k, helpArr);
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= m; j++){
      delete [] helpArr[i][j];
    }
    delete [] helpArr[i];
  }
  delete [] helpArr;
  return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int k;
    string s1, s2;
    cin >> s1 >> s2 >> k;
    cout << solve(s1,s2,k) << endl;
  }
  return 0;
}
*/
