/*
Q. Code Bubble Sort

Provided with a random integer array/list(ARR) of size N, you have been required to sort this array using 'Bubble Sort'.

Note:
Change in the input array/list itself. You don't need to return or print the elements.

Sample Input 1:
1
7
2 13 4 1 3 6 28

Sample Output 1:
1 2 3 4 6 13 28

Sample Input 2:
2
5
9 3 6 2 0
4
4 3 2 1

Sample Output 2:
0 2 3 6 9
1 2 3 4
*/

#include<iostream>
using namespace std;

void printArray(int arr[], int n){
  for(int a = 0; a < n; a++){
    cout << arr[a] << " ";
  }
  cout << endl;
}

void bubbleSort(int arr[], int n){

  for(int j = 0; j < n-1; j++){
    for(int k = 0; k < n-j-1; k++){
      if(arr[k] > arr[k + 1]){
        int temp = arr[k];
        arr[k] =  arr[k+1];
        arr[k+1] = temp;
      }
    }
  }
}

int main(){
  int n;
  cin >> n;

  int arr[10];

  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  bubbleSort(arr,n);
  printArray(arr,n);
}
