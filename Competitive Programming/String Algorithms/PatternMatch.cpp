#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

bool isMatch(string s, string p){
  int n = s.length();
  int m = p.length();
  for(int i = 0; i <= (n-m); i++){
    bool isFound = true;
    for(int j = 0; j < m; j++){
      if(s[i+j] != p[j]){
        isFound = false;
        break;
      }
    }
    if(isFound){
      return true;
    }
  }
  return false;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    string s, p;
    cin >> s >> p;
    cout << (isMatch(s, p) ? "Found" : "Not Found") << endl;
  }
  return 0;
}
