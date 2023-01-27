/*
Q. Quick Sort Code
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.

Sample Input 1 :
6 
2 6 8 5 4 3

Sample Output 1 :
2 3 4 5 6 8

Sample Input 2 :
5
1 5 2 7 3

Sample Output 2 :
1 2 3 5 7 

*/

#include<iostream>
using namespace std;

int partition(int input[], int start, int end){
  int countSmall = 0;
  int pivot = input[start];
  for(int i = start+1; i <= end; i++){
    if(input[i] <= pivot){
      countSmall++;
    }
  }
  int pivotIndex = start + countSmall;
  input[start] = input[pivotIndex];
  input[pivotIndex] = pivot;

  int i = start, j = end;

  while(i < pivotIndex && j > pivotIndex){
    if(input[i] <= pivot){
      i++;
    }else if(input[j] > pivot){
      j--;
    }else{
      int temp = input[i];
      input[i] = input[j];
      input[j] = temp;
      i++;
      j--;
    }
  }
  return pivotIndex;
}

void helperSort(int input[], int start, int end){
  if(start >= end){
    return;
  }
  int c = partition(input,start,end);
  helperSort(input,start,c-1);
  helperSort(input,c+1,end);
}

void quickSort(int input[], int size){
  if(size == 0 || size == 1){
    return;
  }
  helperSort(input,0,size-1);
}

int main(){
  int arr[100], n;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  quickSort(arr,n);
  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
