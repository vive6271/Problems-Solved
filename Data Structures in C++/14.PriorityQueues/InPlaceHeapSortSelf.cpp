#include <iostream>

void heapSort(int arr[], int n) {
    // Write your code

    //Insert
    for(int i = 0; i < n; i++){
      int childIndex = i;
      while(childIndex > 0){
        int parentIndex = (childIndex-1)/2;
        if(arr[childIndex] < arr[parentIndex]){
          int tmp = arr[childIndex];
          arr[childIndex] = arr[parentIndex];
          arr[parentIndex] = tmp;
        }else{
          break;
        }
        childIndex = parentIndex;
      }
    }
    //Delete
    int size = n;
    while(size){
      int tmp = arr[0];
      arr[0] = arr[size-1];
      arr[size-1] = tmp;
      size--;
      int parentIndex = 0;
      int leftChildIndex = (2*parentIndex)+1;
      int rightChildIndex = (2*parentIndex)+2;
      while(leftChildIndex < size){
        int minIndex = parentIndex;
        if(arr[minIndex] > arr[leftChildIndex]){
          minIndex = leftChildIndex;
        }
        if(rightChildIndex < size && arr[minIndex] > arr[rightChildIndex]){
          minIndex = rightChildIndex;
        }
        if(minIndex == parentIndex){
          break;
        }
        int tmp = arr[minIndex];
        arr[minIndex] = arr[parentIndex];
        arr[parentIndex] = tmp;

        parentIndex = minIndex;
        leftChildIndex = (2*parentIndex)+1;
        rightChildIndex = (2*parentIndex)+2;
      }
    }
}

using namespace std;

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    }

    delete[] input;
}
