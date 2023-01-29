#include<iostream>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int a, b, c;
    cin >> a >> b >> c;
    long tmp = 1;
    while(b != 0){
      int bitCheck = b & 1;
      if(bitCheck){
        tmp = (tmp * a) % c;
      }
      a = (long (a*a)) % c;
      b /= 2;
    }
    int ans = int ((tmp + c) % c);
    cout << ans << endl;
  }
  return 0;
}
