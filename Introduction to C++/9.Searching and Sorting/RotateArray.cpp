/*
Q. Rotate array

You have been given a random integer array/list(ARR) of size N. Write a function that rotates the given array/list by D elements(towards the left).
Note:
Change in the input array/list itself. You don't need to return or print the elements.

Sample Input 1:
1
7
1 2 3 4 5 6 7
2

Sample Output 1:
3 4 5 6 7 1 2

Sample Input 2:
2
7
1 2 3 4 5 6 7
0
4
1 2 3 4
2

Sample Output 2:
1 2 3 4 5 6 7
3 4 1 2
*/

#include<iostream>
using namespace std;

void printArray(int arr[], int n){
  for(int j = 0; j < n; j++){
    cout << arr[j] << " ";
  }
  cout << endl;
}

void swapElements(int arr[], int i, int j){
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
void reverse(int arr[], int start, int end){
  int i = start, j = end;
  while (i < j){
    swapElements(arr, i, j);
    i++;
    j--;
  }
}


void rotateArray(int arr[], int n, int d){
  if (d >= n && n != 0){
    d = d % n;
  }else if (n == 0){
    return;
  }
  reverse(arr, 0, n - 1);
  reverse(arr, 0, n - d - 1);
  reverse(arr, n - d, n - 1);





  //int rotate = 0;
  //for(int k = n; k < n+d; k++){
    //arr[k] = arr[rotate];
    //rotate++;
  //}
  //int start = 0;
  //for(int l = d; l < n+d; l++){
    //arr[start] = arr[l];
    //start++;
  //}

  //* int arrTemp[10];
  //for(int k = 0; k < d; k++){
  //  arrTemp[k] = input[k];
  //}
  //int start = 0;
  //for(int l = d; l < n; l++){
  //  input[start] = input[l];
  //  start++;
  //}
  //int end = 0;
  //for(int m = n-d; m < n; m++){
    //input[m] = arrTemp[end];
    //end++;
  //}

}

int main(){
  int n;
  cin >> n;

  int arr[20];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  int d;
  cin >> d;

  rotateArray(arr,n,d);
  printArray(arr,n);
}
