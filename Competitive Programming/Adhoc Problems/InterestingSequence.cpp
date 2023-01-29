#include<bits/stdc++.h>
using namespace std;
#define int long long

int countDiff(int *arr, int n, int num, int k, int l){
  int inc = 0, dec = 0;
  for(int i = 0; i < n; i++){
    if(arr[i] < num){
      inc += num - arr[i];
    }else{
      dec += arr[i] - num;
    }
  }
  if(dec > inc){
    return (int) 1e15;
  }
  return (dec * k) + ((inc - dec) * l);
}

int32_t main(){
  int n, k, l;
  cin >> n >> k >> l;

  int *arr = new int[n];
  int minNum = INT_MAX, maxNum = INT_MIN;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
    if(minNum > arr[i]){
      minNum = arr[i];
    }
    if(maxNum < arr[i]){
      maxNum = arr[i];
    }
  }

  int minCost = (int) 1e15;
  for(int i = minNum; i <= maxNum; i++){
    minCost = min(minCost, countDiff(arr, n, i, k, l));
  }
  cout << minCost << endl;
  delete [] arr;
  return 0;
}
