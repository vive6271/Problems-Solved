#include<iostream>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int ans = n, num = n;
    for(int i = 2; i*i <= n; i++){
      if(num % i == 0){
        while(num % i == 0){
          num /= i;
        }
        ans -= ans/i;
      }
    }
    if(num > 1){
      ans -= ans/num;
    }
    cout << ans << endl;
  }
  return 0;
}
