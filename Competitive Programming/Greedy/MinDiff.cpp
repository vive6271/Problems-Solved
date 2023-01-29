#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }
    sort(arr,arr+n);
    int minDiff = INT_MAX;
    for(int i = 1; i < n; i++){
      int tmp = arr[i] - arr[i-1];
      if(tmp < minDiff){
        minDiff = tmp;
      }
    }
    cout << minDiff << endl;
    delete [] arr;
  }
  return 0;
}
