#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

int* getLPS(string pattern){
  int len = pattern.length();
  int* lps = new int[len];

  lps[0] = 0;
  int i = 1, j = 0;
  while(i < len){
    if(pattern[i] == pattern[j]){
      lps[i] = j+1;
      i++;
      j++;
    }else{
      if(j != 0){
        j = lps[j-1];
      }else{
        lps[i] = 0;
        i++;
      }
    }
  }
  return lps;
}

bool kmpSearch(string text, string pattern){
  int lenText = text.length();
  int lenPatt = pattern.length();
  int* lps = getLPS(pattern);
  int i = 0, j = 0;
  while(i < lenText && j < lenPatt){
    if(text[i] == pattern[j]){
      i++;
      j++;
    }else{
      if(j != 0){
        j = lps[j-1];
      }else{
        i++;
      }
    }
  }
  delete [] lps;
  if(j == lenPatt){
    return true;
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
    cout << (kmpSearch(s, p) ? "Found" : "Not Found") << endl;
  }
  return 0;
}
