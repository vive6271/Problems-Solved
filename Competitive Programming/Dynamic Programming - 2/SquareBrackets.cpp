#include<iostream>
using namespace std;
int MOD = 10000000007;

int squareBrackets(int open, int close, int n, bool *fixed, int **helpArr){
  if(open > n || close > n){
    return 0;
  }
  if(open == n && close == n){
    return 1;
  }
  if(helpArr[open][close] != -1){
    return helpArr[open][close];
  }
  int ans;
  if(open == close || fixed[0] == true){
    ans = squareBrackets(open+1, close, n, fixed+1, helpArr);
  }else if(open == n){
    ans = squareBrackets(open, close+1, n, fixed+1, helpArr);
  }else{
    ans = ((long long)squareBrackets(open+1, close, n, fixed+1, helpArr) + squareBrackets(open, close+1, n, fixed+1, helpArr)) % MOD;
  }
  helpArr[open][close] = ans;
  return ans;
}

int square(int n, bool *fixed){
  int **helpArr = new int*[n+1];
  for(int i = 0; i <= n; i++){
    helpArr[i] = new int[n+1];
    for(int j = 0; j <= n; j++){
      helpArr[i][j] = -1;
    }
  }
  int ans = squareBrackets(0, 0, n, fixed, helpArr);
  for(int i = 0; i <= n; i++){
    delete [] helpArr[i];
  }
  delete [] helpArr;
  return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    bool *fixed = new bool[2*n](); // VVI  see for bool array
    for(int i = 0; i < k; i++){
      int a;
      cin >> a;
      fixed[a-1] = true;
    }
    cout << square(n,fixed) << endl;
    delete [] fixed;
  }
  return 0;
}
