#include<iostream>
using namespace std;

int sum(int a[], int size, int startIndex = 0){
  int sum  = 0;
  for(int i = startIndex; i < size; i++){
    sum += a[i];
  }
  return sum;
}

int main() {
  int arr[10];
  cout << "Enter Array of 5 Numbers : ";
  for(int i = 0; i < 5; i++){
    cin >> arr[i];
  }
  cout << sum(arr,5) << endl;
  cout << sum(arr,5,2) << endl;
}
