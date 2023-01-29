#include<bits/stdc++.h>
using namespace std;

void strangeOrder(int n){
  int *sieve = new int[n+1];
  bool *marked = new bool[n+1];
  for(int i = 0; i <= n; i++){
    sieve[i] = i;
    marked[i] = false;
  }
  for(int i = 2; i*i <= n; i++){
    if(sieve[i] == i){
      for(int j = 2*i; j <= n; j += i){
        if(sieve[j] == j){
          sieve[j] = i;
        }
      }
    }
  }

  for(int i = n; i >= 1; i--){
    if(!marked[i]){
      vector<int> v;
      int lpd = sieve[i];
      v.push_back(i);
      marked[i] = true;
      int num = i;
      while(lpd != 1){
        for(int j = i-lpd; j > 1; j -= lpd){
          if(!marked[j]){
            v.push_back(j);
            marked[j] = true;
          }
        }
        while(num % lpd == 0){
          num /= lpd;
        }
        lpd = sieve[num];
      }
      sort(v.begin(), v.end(), greater<int>());
      for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
      }
    }
  }
  cout << endl;
  delete [] marked;
  delete [] sieve;
}

int main(){
  int n;
  cin >> n;
  strangeOrder(n);
  return 0;
}
