#include<iostream>
using namespace std;
int N = 1000000;

void preComputation(int **nFactor){
  int *prime = new int[N+1];
  for(int i = 0; i <= N; i++){
    prime[i] = 0;
  }
  for(int i = 2; i <= N; i += 2){
    prime[i]++;
  }
  for(int i = 3; i <= N; i += 2){
    if(prime[i] == 0){
      for(int j = i; j <= N; j += i){
        prime[j]++;
      }
    }
  }
  for(int i = 1; i <= 10; i++){
    for(int j = 1; j <= N; j++){
      if(prime[j] == i){
        nFactor[i][j] = 1 + nFactor[i][j-1];
      }else{
        nFactor[i][j] = nFactor[i][j-1];
      }
    }
  }
  delete [] prime;
}

int main(){
  int t;
  cin >> t;
  int **nFactor = new int*[11];
  for(int i = 0; i <= 10; i++){
    nFactor[i] = new int[N+1];
  }
  preComputation(nFactor);
  while(t--){
    int a, b, n;
    cin >> a >> b >> n;
    cout << (nFactor[n][b]-nFactor[n][a-1]) << endl;
  }
  for(int i = 0; i <= 10; i++){
    delete [] nFactor[i];
  }
  delete [] nFactor;
  return 0;
}
