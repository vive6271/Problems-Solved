#include<iostream>
using namespace std;

int main(){
  int n, n1 = 0, n2 = 0;
  cin >> n;
  bool *prime = new bool[n+2];
  for(int i = 0; i <= n+1; i++){
    prime[i] = true;
  }
  for(int i = 2; i*i <= n+1; i++){
    if(prime[i]){
      for(int j = i*i; j <= n+1; j += i){
        prime[j] = false;
      }
    }
  }
  for(int i = 2; i <= n+1; i++){
    if(prime[i]){
      n1++;
    }else{
      n2++;
    }
  }
  if(n <= 1){
    cout << 1 << endl;
  }else{
    cout << 2 << endl;
  }
  cout << min(n1,n2) << " " << max(n1,n2) << endl;
  delete [] prime;
  return 0;
}
