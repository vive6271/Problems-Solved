#include<iostream>
using namespace std;

void printArray(int array[], int n){
  for(int j = 0; j < n; j++){
    cout << array[j] << " ";
  }
  cout << endl;
}

void reverse(int array[], int n){
  int a = 0;
  int b = (n - 1);
  int temp;
  while(a < b){
    temp = array[a];
    array[a] = array[b];
    array[b] = temp;
    a++;
    b--;
  }
}

int main(){
  int n;
  cin >> n;
  int array[10];

  for(int i = 0; i < n; i++){
    cin >> array[i];
  }

  reverse(array , n);

  printArray(array, n);

}
