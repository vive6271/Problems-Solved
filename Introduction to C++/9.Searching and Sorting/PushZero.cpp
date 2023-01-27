#include<iostream>
using namespace std;

void printArray(int arr[], int n){
  for(int j = 0; j < n; j++){
    cout << arr[j] << " ";
  }
  cout << endl;
}

void pushZero(int arr[], int n){
  int temp;
  int zero = 0;
  int max = 0;
  int large = 0;
  while(max <= large){
    for(int k = 0; k < n; k++){
      if(arr[k] == max){
        temp = arr[k];
        arr[k] = arr[zero];
        arr[zero] = temp;
        zero++;
      }
      if (arr[k] > arr[k+1]){
        large = arr[k];
      }
    }
    max++;
  }
}

int main(){
  int n;
  cin >> n;

  int arr[100];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  pushZero(arr,n);
  printArray(arr,n);
}
