#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string str;
  cin >> str;
  int n = str.length();
  int x = 0, y = 0, prev, areaCover = 0;
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    prev = x;
    if(str[i] == 'E'){
      x += a;
    }else if(str[i] == 'W'){
      x -= a;
    }else if(str[i] == 'N'){
      y += a;
    }else if(str[i] == 'S'){
      y -= a;
    }
    areaCover += (x - prev) * y;
  }
  cout << abs(areaCover) << endl;
  return 0;
}
