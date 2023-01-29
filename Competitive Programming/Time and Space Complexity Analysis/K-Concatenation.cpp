#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll kadane(int *arr, int n){
  ll curr_sum = 0;
  ll max_so_far = INT_MIN;
  for(int i = 0; i < n; i++){
    curr_sum += arr[i];
    if(max_so_far < curr_sum){
      max_so_far = curr_sum;
    }
    if(curr_sum < 0){
      curr_sum = 0;
    }
  }
  return max_so_far;
}

ll maxSubArraySum(int *arr, int n, int k){
  ll kadane_sum = kadane(arr,n);
  if(k == 1){
    return kadane_sum;
  }
  ll curr_perfix_sum = 0, curr_suffix_sum = 0;
  ll max_perfix_sum = INT_MIN, max_suffix_sum = INT_MIN;

  for(int i = 0; i < n; i++){
    curr_perfix_sum += arr[i];
    max_perfix_sum = max(curr_perfix_sum,max_perfix_sum);
  }
  ll totalSum = curr_perfix_sum;
  for(int i = n-1; i >= 0; i--){
    curr_suffix_sum += arr[i];
    max_suffix_sum = max(curr_suffix_sum,max_suffix_sum);
  }
  ll ans;
  if(totalSum < 0){
    ans = max(max_perfix_sum + max_suffix_sum, kadane_sum);
  }else{
    ans = max(max_perfix_sum + max_suffix_sum + (totalSum * (k-2)), kadane_sum);
  }
  return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }

    cout << maxSubArraySum(arr, n, k) << endl;
    delete[] arr;
  }
  return 0;
}
