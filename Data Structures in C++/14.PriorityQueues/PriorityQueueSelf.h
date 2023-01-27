#include <vector>
#include <iostream>
using namespace std;
template <typename T>
class PriorityQueue{
  vector<T> pq;

  void balanceHeap(){

  }
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
  void insert(T data){
    pq.push_back(data);
    if(pq.size() > 1){
      int child = (pq.size()-1);
      int parent = (child-1)/2;
      while((parent >= 0) && pq[child] < pq[parent]){
        T tmp = pq[child];
        pq[child] = pq[parent];
        pq[parent] = tmp;
        child = parent;
        parent = (child-1)/2;
      }
    }
  }

  T remove(){
    if(pq.size() == 0){
      return 0;
    }
    T ans = pq[0];
    pq[0] = pq[pq.size()-1];
    pq.pop_back();
    int parentIndex = 0;
    int leftChildIndex = (2*parentIndex+1), rightChildIndex = (2*parentIndex+2);
    while(leftChildIndex < pq.size() && (pq[parentIndex] > pq[leftChildIndex] || pq[parentIndex] > pq[rightChildIndex])){
      int swapIndex = leftChildIndex;
      if(pq[swapIndex] > pq[rightChildIndex]){
        swapIndex = rightChildIndex;
      }
      T tmp = pq[parentIndex];
      pq[parentIndex] = pq[swapIndex];
      pq[swapIndex] = tmp;
      parentIndex = swapIndex;
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
