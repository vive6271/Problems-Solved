#include<iostream>
using namespace std;

void printArray2D(int arr[][2], int m, int n){
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

int main(){
  int arr[][2] = {{1,2} , {3,4}};
  printArray2D(arr, 2, 2);
}
