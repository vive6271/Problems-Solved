#include<iostream>
using namespace std;

void printArray(int arr[], int n){
  for(int l = 0; l < n; l++){
    cout << arr[l] << " ";
  }
  cout << endl;
}

void selectionSort(int arr[] , int n){
  for(int i = 0; i < n-1; i++){
    int minNum = arr[i], minIndex = i;
    for(int j = i+1; j < n; j++){
      if(arr[j] < minNum){
        minNum = arr[j];
        minIndex = j;
      }
    }
    if(minIndex != i){
      int tmp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = tmp;
    }
  }
}

int main() {
  int n;
  cin >> n;

  int arr[10];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  selectionSort(arr, n);
  printArray(arr, n);

}
