/*
Q. Swap Alternate

You have been given an array/list(ARR) of size N. You need to swap every pair of alternate elements in the array/list.
You don't need to print or return anything, just change in the input array itself.

Sample Input 1:
1
6
9 3 6 12 4 32

Sample Output 1 :
3 9 12 6 32 4

Sample Input 2:
2
9
9 3 6 12 4 32 5 11 19
4
1 2 3 4

Sample Output 2 :
3 9 12 6 32 4 11 5 19 
2 1 4 3

*/

#include<iostream>
using namespace std;

void printArray(int array[], int n){
  for(int j = 0; j < n; j++){
    cout << array[j] << " ";
  }
  cout << endl;
}

void swapAlternate(int array[], int n){

  int k = 0;
  int temp ;

  if(n % 2 == 0){
    while(k < n){
      temp = array[k];
      array[k] = array[k+1];
      array[k+1] = temp;
      k += 2;
    }
  }else if(n % 2 == 1){
   while(k < n -1){
     temp = array[k];
     array[k] = array[k+1];
     array[k+1] = temp;
     k += 2;
   }
 }
}

int main(){
  int n;
  cin >> n;

  int array[10];

  for(int i = 0; i < n; i++){
    cin >> array[i];
  }

  swapAlternate(array, n);

  printArray(array,n);

}
