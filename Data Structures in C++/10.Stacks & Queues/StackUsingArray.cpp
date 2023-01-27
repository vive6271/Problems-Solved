#include<climits>

class StackUsingArray{
  int *data;
  int nextIndex;
  int capacity;

public:
  StackUsingArray(int totalSize){
    data = new int[totalSize];
    nextIndex = 0;
    capacity = totalSize;
  }

  //Return the number of elements present in the stack

  int size(){
    return nextIndex;
  }

  bool isEmpty(){
    return nextIndex == 0;
  }

  //Insert element

  void push(int element){
    if(nextIndex == capacity){
      cout << "Stack is Full" << endl;
      return;
    }
    data[nextIndex] = element;
    nextIndex++;
  }

  //Delete element

  int pop(){
    if(isEmpty()){
      cout << "Stack is Empty" << endl;
      return INT_MIN;
    }
    nextIndex--;
    return data[nextIndex];
  }

  int top(){
    if(isEmpty()){
      cout << "Stack is Empty" << endl;
      return INT_MIN;
    }
    return data[nextIndex-1];
  }
};
