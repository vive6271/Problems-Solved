#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;
    int *start = new int[n+1];
    int *end = new int[n+1];
    int *coinCount = new int[n+1];
    int *atleastCoin = new int[n+1];

    for(int i = 0; i <= n; i++){
      start[i] = 0;
      end[i] = 0;
      coinCount[i] = 0;
      atleastCoin[i] = 0;
    }
    
    for(int i = 0; i < m; i++){
      int s, e;
      cin >> s >> e;
      start[s]++;
      end[e]++;
    }

    coinCount[1] = start[1];
    int lastVal = start[1];
    for(int i = 2; i <= n; i++){
      lastVal = start[i] - end[i-1] + lastVal;
      coinCount[i] = lastVal;
    }
    delete [] start;
    delete [] end;
    for(int i = 1; i <= n; i++){
      atleastCoin[coinCount[i]]++;
    }
    delete [] coinCount;
    for(int i = n-1; i >= 0; i--){
      atleastCoin[i] += atleastCoin[i+1];
    }
    int q;
    cin >> q;
    while(q--){
      int i;
      cin >> i;
      cout << atleastCoin[i] << endl;
    }
    delete [] atleastCoin;
  }
  return 0;
}
