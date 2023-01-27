/*
Q. Running Median

You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.
Print only the integer part of the median.

Sample Input 1 :
6
6 2 1 3 7 5

Sample Output 1 :
6 4 2 2 3 4

Explanation of Sample Output 1 :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4

Sample Input 2 :
5
5 4 3 2 1

Sample Output 2 :
5 4 4 3 3
*/

#include <iostream>
#include<queue>
using namespace std;

void findMedian(int *arr, int n){
    // Write your code here
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;

    for(int i = 0; i < n; i++){
      if(i == 0){
        max.push(arr[i]);
        cout << max.top() << " ";
        continue;
      }
      if(max.top() > arr[i]){
        max.push(arr[i]);
      }else{
        min.push(arr[i]);
      }
      int difSize = max.size() - min.size();
      if(difSize > 1){
        min.push(max.top());
        max.pop();
      }else if(difSize < -1){
        max.push(min.top());
        min.pop();
      }
      if((max.size()+min.size()) % 2 == 0){
        cout << (max.top()+min.top()) / 2 << " ";
      }else if(max.size() > min.size()){
        cout << max.top() << " ";
      }else{
        cout << min.top() << " ";
      }
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}
