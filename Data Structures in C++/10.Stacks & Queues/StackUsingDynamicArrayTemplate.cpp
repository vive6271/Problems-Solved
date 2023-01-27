template<typename T>

class StackUsingArray{
  T *data;
  int nextIndex;
  int capacity;

public:
  StackUsingArray(){
    data = new T[5];
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

  void push(T element){
    if(nextIndex == capacity){
      T *newData = new T[2 * capacity];
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

  T pop(){
    if(isEmpty()){
      cout << "Stack is Empty" << endl;
      return 0;
    }
    nextIndex--;
    return data[nextIndex];
  }

  T top(){
    if(isEmpty()){
      cout << "Stack is Empty" << endl;
      return 0;
    }
    return data[nextIndex-1];
  }
};
