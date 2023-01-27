#include <vector>
#include <iostream>
using namespace std;
template <typename T>
class PriorityQueue{
  vector<T> pq;
public:
  PriorityQueue(){

  }

  bool isEmpty(){
    return pq.size() == 0;
  }

  //Returns the size of PriorityQueue - no of elements present
  int getSize(){
    return pq.size();
  }

  T getMin(){
    if(isEmpty()){
      return -1; //PriorityQueue is Empty
    }
    return pq[0];
  }
  void insert(T element){
    pq.push_back(element);
    int childIndex = pq.size()-1;
    while(childIndex > 0){
      int parentIndex = (childIndex-1)/2;
      if(pq[childIndex] < pq[parentIndex]){
        T tmp = pq[childIndex];
        pq[childIndex] = pq[parentIndex];
        pq[parentIndex] = tmp;
      }else{
        break;
      }
      childIndex = parentIndex;
    }
  }

  T removeMin(){
    if(isEmpty()){
      return 0;
    }
    T ans = pq[0];
    pq[0] = pq[pq.size()-1];
    pq.pop_back();

    //Down heapify

    int parentIndex = 0;
    int leftChildIndex = (2*parentIndex+1);
    int rightChildIndex = (2*parentIndex+2);

    while(leftChildIndex  < pq.size()){
      int minIndex = parentIndex;
      if(pq[minIndex] > pq[leftChildIndex]){
        minIndex = leftChildIndex;
      }
      if(rightChildIndex < pq.size() && pq[minIndex] > pq[rightChildIndex]){
        minIndex = rightChildIndex;
      }
      if(minIndex == parentIndex){
        break;
      }
      T tmp = pq[minIndex];
      pq[minIndex] = pq[parentIndex];
      pq[parentIndex] = tmp;

      parentIndex = minIndex;
      leftChildIndex = (2*parentIndex+1);
      rightChildIndex = (2*parentIndex+2);
    }
    return ans;
  }
  void print(){
    for(int i = 0; i < pq.size(); i++){
      cout << pq[i] << " ";
    }
    cout << endl;
  }
};
