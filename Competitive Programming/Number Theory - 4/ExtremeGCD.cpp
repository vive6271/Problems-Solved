#include<iostream>
#include<cmath>
using namespace std;
#define N 100001
long long phi[N], result[N];

void totientFunction(){
  for(int i = 0; i < N; i++){
    phi[i] = i;
    result[i] = 0;
  }

  for(int i = 2; i < N; i++){
    if(phi[i] == i){
      phi[i] = i-1;
      double a = double (i-1)/i;
      for(int j = 2*i; j <= N; j += i){
        phi[j] = round(double (a * phi[j]));
      }
    }
  }
}

void extremeGCD(){
  totientFunction();
  for(int i = 1; i < N; i++){
    for(int j = 2; i*j < N; j++){
      result[i*j] += i * phi[j];
    }
  }
  for(int i = 2; i < N; i++){
    result[i] += result[i-1];
  }
}

int main(){
  extremeGCD();
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    cout << result[n] << endl;
  }
  return 0;
}
