#include<climits>

class StackUsingArray{
  int *data;
  int nextIndex;
  int capacity;

public:
  StackUsingArray(){
    data = new int[5];
    nextIndex = 0;
    capacity = 5;
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
      int *newData = new int[2 * capacity];
      for(int i = 0; i < capacity; i++){
        newData[i] = data[i];
      }
      capacity *= 2;
      delete [] data;
      data = newData;
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
