#include<iostream>
using namespace std;

int minChocolates(int *arr, int n){
  int *output = new int[n];
  output[0] = 1;
  //Left -> Right
  for(int i = 1; i < n; i++){
    if(arr[i] > arr[i-1]){
      output[i] = 1 + output[i-1];
    }else{
      output[i] = 1;
    }
  }
  //Right -> Left
  int sum = output[n-1];
  for(int i = n-2; i >= 0; i--){
    if(arr[i] > arr[i+1] && output[i] <= output[i+1]){
      output[i] = 1 + output[i+1];
    }
    sum += output[i];
  }
  delete [] output;
  return sum;
}

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
    cout << minChocolates(arr,n) << endl;
    delete [] arr;
  }
}
