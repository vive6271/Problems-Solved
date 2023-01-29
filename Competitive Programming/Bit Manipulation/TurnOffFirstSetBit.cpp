#include<iostream>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, i = 1, k = 0;
    cin >> n;
    while(!k){
      k = n & i;
      i = i << 1;
    }
    cout << (n ^ k) << endl;
  }
  return 0;
}
