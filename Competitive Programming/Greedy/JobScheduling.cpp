#include<bits/stdc++.h>
using namespace std;

struct Job{
  int start, finish, profit;
};

bool compare(struct Job j1, struct Job j2){
  return (j1.finish < j2.finish);
}


// TC :- O(N^2)
/*
int jobScheduling(struct Job *arr, int n){
  sort(arr, arr+n, compare);
  int *dp = new int[n];
  dp[0] = arr[0].profit;
  for(int i = 1; i < n; i++){
    dp[i] = 0;
    for(int j = i-1; j >= 0; j--){
      if(arr[j].finish <= arr[i].start){
        int value = dp[j] + arr[i].profit;
        if(dp[i] < value){
          dp[i] = value;
        }
      }else{
        if(arr[j].profit < arr[i].profit){
          dp[i] = arr[i].profit;
        }else{
          dp[i] = dp[i-1];
        }
      }
    }
  }
  int ans = dp[n-1];
  delete [] dp;
  return ans;
}
*/

int binarySearch(struct Job *arr, int n){
  int start = 0, end = n-1, mid = 0;
  while(start <= end){
    mid = (start+end) / 2;
    if(arr[mid].finish <= arr[n].start){
      if(arr[mid+1].finish <= arr[n].start){
        start = mid+1;
      }else{
        return mid;
      }
    }else{
      end = mid-1;
    }
  }
  return -1;
}

int jobScheduling(struct Job *arr, int n){
  sort(arr, arr+n, compare);
  int *dp = new int[n];
  dp[0] = arr[0].profit;
  for(int i = 1; i < n; i++){
    int index = binarySearch(arr, i);
    if(index == -1){
      if(arr[i].profit > dp[i-1]){
        dp[i] = arr[i].profit;
      }else{
        dp[i] = dp[i-1];
      }
      continue;
    }
    int value = dp[index] + arr[i].profit;
    if(value > dp[i-1]){
      dp[i] = value;
    }else{
      dp[i] = dp[i-1];
    }
  }

  int ans = dp[n-1];
  delete [] dp;
  return ans;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  Job *arr = new Job[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i].start >> arr[i].finish >> arr[i].profit;
  }
  cout << jobScheduling(arr,n) << endl;
  delete [] arr;
  return 0;
}
