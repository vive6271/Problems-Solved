#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    int Area = (x1-x2)*(y2-y3) - (y1-y2)*(x2-x3);
    if(Area == 0){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
  return 0;
}
