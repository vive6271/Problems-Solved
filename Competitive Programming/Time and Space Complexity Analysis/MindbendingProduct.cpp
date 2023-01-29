#include<iostream>
using namespace std;

void mindbendingProduct(int *arr, int n, long *output){
  long multi = 1;
  for(int i = 0; i < n; i++){
    output[i] = multi;
    multi *= arr[i];
  }
  multi = 1;
  for(int i = n-1; i >= 0; i--){
    output[i] *= multi;
    multi *= arr[i];
  }
}

int main(){
  int n;
  cin >> n;
  int *arr = new int[n];
  long *output = new long[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  mindbendingProduct(arr, n, output);
  for(int i = 0; i < n; i++){
    cout << output[i] << " ";
  }
  cout << endl;
  delete [] arr;
  delete [] output;
  return 0;
}
