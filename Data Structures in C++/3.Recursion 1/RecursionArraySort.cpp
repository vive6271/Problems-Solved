#include<iostream>
using namespace std;

bool isSorted(int arr[], int n){
  if(n == 0 || n == 1){
    return true;
  }
  if(arr[0] > arr[1]){
    return false;
  }
  bool smallSorted = isSorted(arr+1, n-1);
  return smallSorted;
}

int main(){
  int n, arr[100];
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  bool isTrue = isSorted(arr,n);
  if(isTrue == true){
    cout << "Sorted" << endl;
  }else{
    cout << "Not Sorted" << endl;
  }
}
