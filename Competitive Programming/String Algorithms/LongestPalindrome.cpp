#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

int longestPalindrome(string str){
  int maxLen = 0;
  int n = str.length();

  for(int i = 0; i < n; i++){
    //Odd length
    int l = i, r= i;
    while(l >= 0 && r < n && str[l] == str[r]){
      int currLen = r-l+1;
      if(currLen > maxLen){
        maxLen = currLen;
      }
      l--;
      r++;
    }

    //Even length
    l = i, r = i+1;
    while(l >= 0 && r < n && str[l] == str[r]){
      int currLen = r-l+1;
      if(currLen > maxLen){
        maxLen = currLen;
      }
      l--;
      r++;
    }
  }
  return maxLen;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    string str;
    cin >> str;
    cout << longestPalindrome(str) << endl;
  }
  return 0;
}
