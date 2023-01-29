#include<iostream>
using namespace std;
#define int long long
int N = 100000;

void preComputation(int *sum){
  int *phi = new int[N+1];
  for(int i = 1; i <= N; i++){
    phi[i] = i;
    sum[i] = 0;
  }
  for(int i = 2; i <= N; i++){
    if(phi[i] == i){
      phi[i] = i-1;
      for(int j = 2*i; j <= N; j += i){
        phi[j] = (phi[j] * (i-1)) / i;
      }
    }
  }
  for(int i = 1; i <= N; i++){
    for(int j = i; j <= N; j += i){
      sum[j] += (i * phi[i]);
    }
  }
  delete [] phi;
  return;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  int *sum = new int[N+1];
  preComputation(sum);
  while(t--){
    int n;
    cin >> n;
    int ans = sum[n]+1;
    ans *= n;
    ans /= 2;
    cout << ans << endl;
  }
  delete [] sum;
  return 0;
}
