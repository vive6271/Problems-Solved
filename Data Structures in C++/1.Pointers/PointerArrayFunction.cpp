#include<iostream>
using namespace std;

void pointerSize(int a[], int size){
  cout << sizeof(a) << endl;
}

int pointerSum(int *a, int size){
  int sum = 0;
  for(int i = 0; i < size; i++){
    sum += a[i];
  }
  return sum;
}

int main() {
  int a[10] = {0,1,2,3,4,5,6,7,8,9};
  cout << sizeof(a) << endl;

  pointerSize(a,10);

  cout << pointerSum(a,10) << endl;
  cout << pointerSum(a+3,7) << endl;
  return 0;
}
