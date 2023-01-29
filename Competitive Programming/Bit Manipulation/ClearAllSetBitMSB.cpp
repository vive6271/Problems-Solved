#include<iostream>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, i, m;
    cin >> n >> i;
    m = ((1 << i) - 1);
    cout << (n & m) << endl;
  }
  return 0;
}
