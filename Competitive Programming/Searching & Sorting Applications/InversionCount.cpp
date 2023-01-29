#include <iostream>
using namespace std;

long long merge_helper(long long *arr, int start, int mid, int end){
  long long inversionCount = 0;
  int arrSize = (end-start) + 1;
  long long *newArr = new long long[arrSize];
  int i = start, j = mid, k = 0;
  while(i < mid && j <= end){
    if(arr[i] <= arr[j]){
      newArr[k] = arr[i];
      i++;
      k++;
    }else{
      newArr[k] = arr[j];
      inversionCount += (mid-i);
      j++;
      k++;
    }
  }
  while(i < mid){
    newArr[k] = arr[i];
    i++;
    k++;
  }
  while(j <= end){
    newArr[k] = arr[j];
    j++;
    k++;
  }

  k = 0;
  for(int i = start; i <= end; i++){
    arr[i] = newArr[k];
    k++;
  }
  delete [] newArr;
  return inversionCount;
}

long long merge_sort(long long *arr, int start, int end){
  if(start >= end){
    return 0;
  }
  int mid = (start+end) / 2;
  long long left_inversion = merge_sort(arr, start, mid);
  long long right_inversion = merge_sort(arr, mid+1, end);
  long long merge_inversion = merge_helper(arr, start, mid+1, end);
  return left_inversion + right_inversion + merge_inversion;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    return merge_sort(arr, 0, n-1);
}

int main(){
    int n;
    cin >> n;
    long long* arr = new long long[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    cout << getInversions(arr, n);
    delete arr;
}
