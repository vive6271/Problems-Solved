#include<iostream>
using namespace std;

/*
int shortestSubsequence(string s, int sIndex, string v, int vIndex, int **helpArr){
  //Base case
  if(v[0] == '\0'){
    return 1;
  }
  if(s[0] == '\0'){
    return 10001;
  }
  if(helpArr[sIndex][vIndex] != -1){
    return helpArr[sIndex][vIndex];
  }
  int a = shortestSubsequence(s.substr(1), sIndex+1, v, vIndex, helpArr);
  int k = -1;
  for(int i = 0; i < v.length(); i++){
    if(s[0] == v[i]){
      k = i+1;
      break;
    }
  }
  if(k == -1){
    helpArr[sIndex][vIndex] = 1;
    return 1;
  }
  int b = 1 + shortestSubsequence(s.substr(1), sIndex+1, v.substr(k), vIndex+k, helpArr);
  helpArr[sIndex][vIndex] = min(a,b);
  return helpArr[sIndex][vIndex];
}
int subSequence(string s, string v){
  int n = s.length();
  int m = v.length();
  int **helpArr = new int*[n+1];
  for(int i = 0; i <= n; i++){
    helpArr[i] = new int[m+1];
    for(int j = 0; j <= m; j++){
      helpArr[i][j] = -1;
    }
  }
  int ans = shortestSubsequence(s, 0, v, 0, helpArr);
  for(int i = 0; i <= n; i++){
    delete [] helpArr[i];
  }
  delete [] helpArr;
  return ans;
}
*/

int shortestSubsequence(string s, string v){
  int n = s.length();
  int m = v.length();
  int **dp = new int*[n+1];
  int **next = new int*[n+1];
  for(int i = 0; i <= n; i++){
    dp[i] = new int[m+1];
    next[i] = new int[m+1];
  }
  for(int i = 0; i < n; i++){
    int prev = -1;
    for(int j = 0; j < m; j++){
      if(s[i] == v[j]){
        prev = j;
      }
      next[i+1][j+1] = prev;
    }
  }
  for(int i = 1; i <= n; i++){
    dp[i][0] = 1;
  }
  for(int j = 0; j <= m; j++){
    dp[0][j] = 1001;
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(next[i][j] == -1){
        dp[i][j] = 1;
      }else{
        dp[i][j] = min(dp[i-1][j], (1+dp[i-1][next[i][j]]));
      }
    }
  }
  int ans = dp[n][m];
  for(int i = 0; i <= n; i++){
    delete [] dp[i];
    delete [] next[i];
  }
  delete [] dp;
  delete [] next;
  return ans;
}

int main(){
  string s, v;
  cin >> s >> v;
  cout << shortestSubsequence(s,v) << endl;
  return 0;
}
