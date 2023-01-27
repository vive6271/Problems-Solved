/*
Q. Push Zeros to end

You have been given a random integer array/list(ARR) of size N. You have been required to push all the zeros 
that are present in the array/list to the end of it. Also, make sure to maintain the relative order of the non-zero elements.

Note:
Change in the input array/list itself. You don't need to return or print the elements.

You need to do this in one scan of array only. Don't use extra space.

Sample Input 1:
1
7
2 0 0 1 3 0 0

Sample Output 1:
2 1 3 0 0 0 0
 
Explanation for the Sample Input 1 :
All the zeros have been pushed towards the end of the array/list. Another important fact is that the order of the non-zero elements have been maintained as they appear in the input array/list.

Sample Input 2:
2
5
0 3 0 2 0
5
9 0 0 8 2

Sample Output 2:
3 2 0 0 0
9 8 2 0 0 

*/


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
  int nonZero = 0;
  for(int k = 0; k < n; k++){
    if(arr[k] != 0){
      temp = arr[k];
      arr[k] = arr[nonZero];
      arr[nonZero] = temp;
      nonZero++;
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
  pushZero(arr,n);
  printArray(arr,n);
}
