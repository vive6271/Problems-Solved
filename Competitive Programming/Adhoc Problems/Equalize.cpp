#include<iostream>
using namespace std;

int main(){
  int n, cost = 0;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  int i = 0;
  while(i < n){
    if(s1[i] != s2[i]){
      if(s1[i] != s1[i+1] && s2[i] != s2[i+1]){
        cost++;
        i += 2;
        continue;
      }else{
        cost++;
      }
    }
    i++;
  }
  cout << cost << endl;
  return 0;
}
