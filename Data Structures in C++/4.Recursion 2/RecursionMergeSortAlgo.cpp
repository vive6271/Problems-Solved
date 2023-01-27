/*
Q. Merge Sort Code

Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.

Sample Input 1 :
6 
2 6 8 5 4 3

Sample Output 1 :
2 3 4 5 6 8

Sample Input 2 :
5
2 1 5 2 3

Sample Output 2 :
1 2 2 3 5 

*/

#include<iostream>
using namespace std;

void merge(int input[], int start, int mid, int end){
  int i = start, j = mid+1, k = 0;
  int size = end - start + 1;
  int* array = new int[size];
  while(i <= mid && j <= end){
    if(input[i] < input[j]){
      array[k] = input[i];
      i++;
      k++;
    }else{
      array[k] = input[j];
      j++;
      k++;
    }
  }
  while(i <= mid){
    array[k] = input[i];
    i++;
    k++;
  }
  while(j <= end){
    array[k] = input[j];
    j++;
    k++;
  }
  int m = 0;
  for(int a = start; a <= end; a++){
    input[a] = array[m];
    m++;
  }
  delete [] array;
}

void helperSort(int input[], int start, int end){
  if(start >= end){
    return;
  }
  int mid = (start+end)/2;
  helperSort(input,start,mid);
  helperSort(input,mid+1,end);
  merge(input,start,mid,end);
}

void mergeSort(int input[], int size){
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
  mergeSort(arr,n);
  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
