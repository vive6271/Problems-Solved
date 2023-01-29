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

int readyPlayer(string text, string pattern){
  int lenText = text.length();
  int lenPatt = pattern.length();
  int* lps = getLPS(pattern);
  int i = 0, j = 0, count = 0;
  while(i < lenText){
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
    if(j == lenPatt){
      j = lps[j-1];
      count++;
    }
  }
  delete [] lps;
  return count;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  string str1, str2;
  cin >> str1 >> str2;
  int ans = readyPlayer(str1, str2.substr(0,k));
  cout << ((ans != 0) ? ans : -1) << endl;
  return 0;
}
