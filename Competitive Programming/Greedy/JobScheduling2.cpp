#include<bits/stdc++.h>
using namespace std;

struct Job{
  int start, finish, profit;
};

bool compare(Job j1, Job j2){
  return (j1.finish < j2.finish);
}

int jobScheduling(Job *arr, int n){
  sort(arr, arr+n, compare);
  int *dp = new int[n];
  dp[0] = arr[0].profit;

  for(int i = 1; i < n; i++){
    int including = arr[i].profit;
    int lNConflict = -1;

    for(int j = i-1; j >= 0; j--){
      if(arr[j].finish <= arr[i].start){
        lNConflict = j;
        break;
      }
    }
    if(lNConflict != -1){
      including += dp[lNConflict];
    }
    dp[i] = max(including,dp[i-1]);
  }
  int ans = dp[n-1];
  delete [] dp;
  return ans;
}

int main(){
  int n;
  cin >> n;
  Job *arr = new Job[n];
  for(int i = 0; i < n; i++){
    cin >> aarr[i].start >> arr[i].finish >> arr[i].profit;
  }
  cout << jobScheduling(arr, n) << endl;
  delete [] arr;
  return 0;
}
