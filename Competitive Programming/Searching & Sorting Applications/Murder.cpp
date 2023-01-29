#include <iostream>
using namespace std;
typedef long long ll;

ll merge(ll *arr, int start, int mid, int end){
  ll count = 0, leftSum = 0;
  int arrSize = (end-start)+1;
  ll *newArr = new ll[arrSize];

  int i = start, j = mid+1, k = 0;
  while(i <= mid && j <= end){
    if(arr[i] < arr[j]){
      leftSum += arr[i];
      newArr[k++] = arr[i++];
    }else{
      newArr[k++] = arr[j++];
      count += leftSum;
    }
  }
  while(i <= mid){
    newArr[k++] = arr[i++];
  }
  while(j <= end){
    newArr[k++] = arr[j++];
    count += leftSum;
  }

  k = 0;
  for(int i = start; i <= end; i++){
    arr[i] = newArr[k++];
  }
  delete [] newArr;
  return count;
}

ll mergeSort(ll *arr, int start, int end){
  if(start >= end){
    return 0;
  }
  int mid = (start+end) / 2;
  ll left_ans = mergeSort(arr, start, mid);
  ll right_ans = mergeSort(arr, mid+1, end);
  ll merge_ans = merge(arr, start, mid, end);
  return left_ans + right_ans + merge_ans;
}

ll murder(ll *arr, int n){
  return mergeSort(arr, 0, n-1);
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    ll *arr = new ll[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }
    cout << murder(arr, n) << endl;
    delete [] arr;
  }
  return 0;
}
