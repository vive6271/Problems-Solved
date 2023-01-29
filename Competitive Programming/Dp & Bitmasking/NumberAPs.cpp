#include<bits/stdc++.h>
using namespace std;
int MOD = 1000000000+7;

int numberAP(int *arr, int n){
  int minNum = INT_MAX, maxNum = INT_MIN;
  for(int i = 0; i < n; i++){
    if(minNum > arr[i]){
      minNum = arr[i];
    }
    if(maxNum < arr[i]){
      maxNum = arr[i];
    }
  }
  int totalAPs = n+1;
  int sum[1001];
  for(int d = (minNum-maxNum); d <= (maxNum-minNum); d++){
    memset(sum, 0, sizeof(sum));
    for(int i = 0; i < n; i++){
      int a = 1;
      if(arr[i]-d >= 1 && arr[i]-d <= 1000){
        a = ((long long) a + sum[arr[i]-d]) % MOD;
      }
      totalAPs = ((long long) totalAPs + a - 1) % MOD;
      sum[arr[i]] = (sum[arr[i]] + a) % MOD;
    }
  }
  return totalAPs;
}

int main(){
  int n;
  cin >> n;
  int *arr = new int[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  cout << numberAP(arr,n) << endl;
  delete [] arr;
  return 0;
}
