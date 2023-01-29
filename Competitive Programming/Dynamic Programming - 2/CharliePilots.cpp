#include<iostream>
using namespace std;

int charliePilots(int *captain, int *assistant, int n, int x, int **helpArr){
  if(n == 0){
    return 0;
  }
  if(helpArr[n][x] != -1){
    return helpArr[n][x];
  }
  int ans;
  if(x == 0){
    ans = assistant[0] + charliePilots(captain+1, assistant+1, n-1, x+1, helpArr);
  }else if(x == n){
    ans = captain[0] + charliePilots(captain+1, assistant+1, n-1, x-1, helpArr);
  }else{
    int a = assistant[0] + charliePilots(captain+1, assistant+1, n-1, x+1, helpArr);
    int b = captain[0] + charliePilots(captain+1, assistant+1, n-1, x-1, helpArr);
    ans = min(a,b);
  }
  helpArr[n][x] = ans;
  return ans;
}

int charlie(int *captain, int *assistant, int n){
  int **helpArr = new int*[n+1];
  int x = n/2;
  for(int i = 0; i <= n; i++){
    helpArr[i] = new int[x+1];
    for(int j = 0; j <= x; j++){
      helpArr[i][j] = -1;
    }
  }
  int ans = charliePilots(captain, assistant, n, 0, helpArr);
  for(int i = 0; i <= n; i++){
    delete [] helpArr[i];
  }
  delete [] helpArr;
  return ans;
}
int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int *captain = new int[n];
    int *assistant  = new int[n];
    for(int i = 0; i < n; i++){
      cin >> captain[i] >> assistant[i];
    }
    cout << charlie(captain, assistant, n) << endl;
    delete [] captain;
    delete [] assistant;
  }
  return 0;
}
