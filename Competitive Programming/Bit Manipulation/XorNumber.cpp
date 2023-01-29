#include<iostream>
using namespace std;


int main(){
  int t;
  cin >> t;
  while(t--){
    int n, rem = 0;
    cin >> n;
    rem = n % 4;
    if(rem == 0){
      cout << n << endl;
    }else if(rem == 1){
      cout << 1 << endl;
    }else if(rem == 2){
      cout << (n+1) << endl;
    }else{
      cout << 0 << endl;
    }
  }
  return 0;
}

/* Too slow
int main(){
  int t;
  cin >> t;
  while(t--){
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
      ans ^= i;
    }
    cout << ans << endl;
  }
  return 0;
}
*/
