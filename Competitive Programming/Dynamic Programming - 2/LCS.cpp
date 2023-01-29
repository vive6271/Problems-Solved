#include<iostream>
#include<string>
#include<cmath>
using namespace std;

/* //Brute Force

int lcs(string str1, string str2){
  if(str1[0] == '\0' || str2[0] == '\0'){
    return 0;
  }

  if(str1[0] == str2[0]){
    return 1 + lcs(str1.substr(1),str2.substr(1));
  }else{
    return max(lcs(str1.substr(1),str2),lcs(str1,str2.substr(1)));
  }
}

//Memoization

int lcsHelper(string str1, int m, string str2, int n, int **arr){
  if(m == 0 || n == 0){
    return 0;
  }

  if(arr[m][n] != -1){
    return arr[m][n];
  }

  int ans;
  if(str1[0] == str2[0]){
    ans = 1 + lcsHelper(str1.substr(1), m-1 , str2.substr(1), n-1, arr);
  }else{
    ans = max(lcsHelper(str1.substr(1), m-1, str2, n, arr), lcsHelper(str1, m, str2.substr(1), n-1, arr));
  }
  arr[m][n] = ans;
  return ans;
}

int lcs(string str1, string str2){
  int m = str1.length();
  int n = str2.length();

  int **arr = new int*[m+1];
  for(int i = 0; i <= m; i++){
    arr[i] = new int[n+1];
    for(int j = 0; j <= n; j++){
      arr[i][j] = -1;
    }
  }
  int ans = lcsHelper(str1, m, str2, n, arr);
  for(int i = 0; i <= m; i++){
    delete [] arr[i];
  }
  delete [] arr;
  return ans;
}

*/

int lcs(string str1, string str2){
  int m = str1.length();
  int n = str2.length();

  int **dp = new int*[m+1];

  for(int i = 0; i <= m; i++){
    dp[i] = new int[n+1];
  }
  for(int i = 0; i <= m; i++){
    dp[i][0] = 0;
  }
  for(int j = 1; j <= n; j++){
    dp[0][j] = 0;
  }

  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){
      if(str1[m-i] == str2[n-j]){
        dp[i][j] = 1 + dp[i-1][j-1];
      }else{
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
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
    cout << lcs(str1,str2) << endl;
  }
  return 0;
}
