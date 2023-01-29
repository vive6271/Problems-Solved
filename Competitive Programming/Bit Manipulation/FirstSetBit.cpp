#include<iostream>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, i = 1, ans = 0;
    cin >> n;
    while(!ans){
      ans = n & i;
      i = i << 1;
    }
    cout << ans << endl;
  }
  return 0;
}
