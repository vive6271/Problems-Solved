#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  string str;
  cin >> str;
  unordered_map<char,int> Map;
  for(int i = 0; i < n; i++){
    Map[str[i]]++;
  }
  cout << Map['a'] << " " << Map['s'] << " " << Map['p'] << endl;
  return 0;
}
