#include<iostream>
using namespace std;

void printArray(int array[], int n){
  for(int i = 0; i < n; i++){
    cout << array[i] << " ";
  }
  cout << endl;
}

int main() {
  int array[10] = { 1, 2, 3, 4};

  printArray( array, 10);
}
