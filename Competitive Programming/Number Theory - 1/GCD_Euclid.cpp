#include<iostream>
using namespace std;

int gcd(int a, int b){
  //Special Case
  if(a < b){
    return gcd(b,a);
  }
  //Base Case
  if(b == 0){
    return a;
  }
  return gcd(b, a%b);
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int a, b;
    cin >> a >> b;
    cout << gcd(a,b) << endl;
  }
  return 0;
}
