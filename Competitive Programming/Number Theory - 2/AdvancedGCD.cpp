#include<iostream>
using namespace std;
typedef long long ll;

int gcd(int a, int b){
  if(b == 0){
    return a;
  }
  return gcd(b, a % b);
}

int stringToInt(int a, string b){
  int n = 0;
  for(int i = 0; b[i] != '\0'; i++){
    n = ((ll) ((ll) (n * 10) % a) + ((b[i]-'0') % a)) % a;
  }
  return n;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int a;
    string b;
    cin >> a >> b;
    cout << gcd(a, stringToInt(a,b)) << endl;
  }
  return 0;
}
