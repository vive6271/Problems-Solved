#include <iostream>
#include <algorithm>
using namespace std;

long variationPairs(int arr[], int n, int k){
  long count = 0;
  sort(arr,arr+n);
  int i = 0, j = 1;
  while(j < n){
    if((arr[j]-arr[i]) >= k){
      count += (n-j);
      i++;
    }else{
      j++;
    }
  }
  return count;
}

int main(){
  int n, k;
  cin >> n >> k;
  int arr[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  cout << variationPairs(arr, n , k) << endl;
  return 0;
}
