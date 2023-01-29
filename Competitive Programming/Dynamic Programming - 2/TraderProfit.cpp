#include<iostream>
#include<climits>
using namespace std;


// Memoization
int tradeProfit(int *arr, int n, int k, int ***helpArr, bool onGoing){
  if(n == 0){
    return 0;
  }
  if(helpArr[n][k][onGoing] != -1){
    return helpArr[n][k][onGoing];
  }

  int a = tradeProfit(arr+1, n-1, k, helpArr, onGoing);
  int b = INT_MIN;
  if(onGoing){
    b = tradeProfit(arr+1, n-1, k-1, helpArr, false) + arr[0];
  }else{
    if(k > 0){
      b = tradeProfit(arr+1, n-1, k, helpArr, true) - arr[0];
    }
  }
  helpArr[n][k][onGoing] = max(0, max(a,b));
  return helpArr[n][k][onGoing];
}


int trade(int *arr, int n, int k){
  int ***helpArr = new int**[n+1];
  for(int i = 0; i <= n; i++){
    helpArr[i] = new int*[k+1];
    for(int j = 0; j <= k; j++){
      helpArr[i][j] = new int[2];
      for(int k = 0; k <= 1; k++){
        helpArr[i][j][k] = -1;
      }
    }
  }
  int ans = tradeProfit(arr, n, k, helpArr, false);
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= k; j++){
      delete [] helpArr[i][j];
    }
    delete [] helpArr[i];
  }
  delete [] helpArr;
  return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int k, n;
    cin >> k >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }
    cout << trade(arr, n, k) << endl;
  }
  return 0;
}
