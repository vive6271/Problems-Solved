#include <vector>
#include <climits>
class PriorityQueue{
  vector<int> pq;

public:
  PriorityQueue() {
       // Implement the constructor here
   }

   /**************** Implement all the public functions here ***************/

   void insert(int element) {
       // Implement the insert() function here
       pq.push_back(element);
       int childIndex = pq.size()-1;
       while(childIndex > 0){
         int parentIndex = (childIndex-1)/2;
         if(pq[childIndex] > pq[parentIndex]){
           int tmp = pq[childIndex];
           pq[childIndex] = pq[parentIndex];
           pq[parentIndex] = tmp;
         }else{
           break;
         }
         childIndex = parentIndex;
       }
   }

   int getMax() {
       // Implement the getMax() function here
       if(isEmpty()){
         return INT_MIN;
       }
       return pq[0];
   }

   int removeMax() {
       // Implement the removeMax() function here
       if(isEmpty()){
         return INT_MIN;
       }
       int ans = pq[0];
       pq[0] = pq[pq.size()-1];
       pq.pop_back();

       int parentIndex = 0;
       int leftChildIndex = (2*parentIndex)+1;
       int rightChildIndex = (2*parentIndex)+2;

       while(leftChildIndex < pq.size()){
         int minIndex = parentIndex;
         if(pq[minIndex] < pq[leftChildIndex]){
           minIndex = leftChildIndex;
         }
         if(rightChildIndex < pq.size() && pq[minIndex] < pq[rightChildIndex]){
           minIndex = rightChildIndex;
         }
         if(minIndex == parentIndex){
           break;
         }
         int tmp = pq[minIndex];
         pq[minIndex] = pq[parentIndex];
         pq[parentIndex] = tmp;

         parentIndex = minIndex;
         leftChildIndex = (2*parentIndex)+1;
         rightChildIndex = (2*parentIndex)+2;
       }
       return ans;
   }

   int getSize() {
       // Implement the getSize() function here
       return pq.size();
   }

   bool isEmpty() {
       // Implement the isEmpty() function here
       return pq.size() == 0;
   }
};
