#include <iostream>
#include <string>
using namespace std;

int lcs(string s, string t){
  if(s.size() == 0 || t.size() == 0){
    return 0;
  }
  //Recursive Call
  if(s[0] == t[0]){
    return 1 + lcs(s.substr(1), t.substr(1));
  }else{
    int a = lcs(s.substr(1), t);
    int b = lcs(s, t.substr(1));
    int c = lcs(s.substr(1), t.substr(1));
    return max(a, max(b,c));
  }
}

int main(){
  string s1, s2;
  cin >> s1 >> s2;
  cout << lcs(s1,s2) << endl;
  return 0;
}
