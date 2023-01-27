/*
Q. Check Max-Heap

Given an array of integers, check whether it represents max-heap or not. Return true if the given array represents max-heap, else return false.

Sample Input 1:
8
42 20 18 6 14 11 9 4

Sample Output 1:
true
*/
#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n) {
    // Write your code here
    for(int i = 0; (2*i)+1 < n; i++){
      int parentIndex = i;
      int leftChildIndex = (2*parentIndex)+1, rightChildIndex = (2*parentIndex)+2;
      if(arr[parentIndex] < arr[leftChildIndex]){
        return false;
      }
      if(rightChildIndex >= n){
        break;
      }
      if(arr[parentIndex] < arr[rightChildIndex]){
        return false;
      }
    }
    return true;
}

/*
bool isMaxHeap(int arr[], int n) {
    // Write your code here
    for(int i = 1; i < n; i++){
        if(arr[i-1] < arr[i]){
            return false;
        }
    }
    return true;
}
*/
int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}
