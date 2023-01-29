#include<iostream>
using namespace std;
typedef long long int ll;

int cubeSquare(ll a, string b, ll m){
  int result = 1;
  int strLength = b.length();
  while(strLength--){
    if(b[strLength] == '1'){
      result = (ll (result * a)) % m;
    }else if(b[strLength] == '2'){
      result = (ll ((ll (result * a)) % m) * a) % m;
    }
    a = (ll ((ll (a*a)) % m) * a) % m;
  }
  return result;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    ll a, m;
    string b;
    cin >> a >> b >> m;
    cout << cubeSquare(a,b,m) << endl;
  }
  return 0;
}
