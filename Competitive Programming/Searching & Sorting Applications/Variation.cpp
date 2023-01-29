#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  int *arr = new int[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  //------------Variation-----------------//
  sort(arr,arr+n);
  int count = 0;
  for(int i = 0, j = i+1; i < n || j < n; i++){
    if(i == j){
      j++;
    }
    while(arr[j]-arr[i] < k && j < n){
      j++;
    }
    if(arr[j]-arr[i] >= k){
      count += (n-j);
    }
  }
  cout << count << endl;
  return 0;
}
