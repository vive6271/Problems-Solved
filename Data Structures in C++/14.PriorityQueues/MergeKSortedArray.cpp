/*
Q. Merge K sorted arrays

Given k different arrays, which are sorted individually (in ascending order). 
You need to merge all the given arrays such that output array should be sorted (in ascending order).

Sample Input 1:
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0

Sample Output 1:
0 1 2 5 6 9 45 78 90 100 234
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    // Write your code here
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < input.size(); i++){
      for(int j = 0; j < input[i] -> size(); j++){
        pq.push(input[i] -> at(j));
      }
    }
    vector<int> ans;
    while(!pq.empty()){
      ans.push_back(pq.top());
      pq.pop();
    }
    return ans;
}

/*
#include <queue>
class Triplet {
public:
  int data;
  int index;
  vector<int> *arr;

  Triplet(int index, vector<int> *arr) {
    this->data = arr->at(index);
    this->index = index;
    this->arr = arr;
  }
};
class Compare {
public:
  bool operator()(Triplet *a, Triplet *b) {
    if (a->data > b->data) {
      return true;
    }
    return false;
  }
};

vector<int> mergeKSortedArrays(vector<vector<int> *> input) {
  // Write your code here
  priority_queue<Triplet *, vector<Triplet *>, Compare> pq;
  int size = input.size();
  for (int i = 0; i < size; i++) {
    Triplet *node = new Triplet(0, input[i]);
    pq.push(node);
  }
  vector<int> ans;
  while (!pq.empty()) {
    Triplet *node = pq.top();
    ans.push_back(node->data);
    pq.pop();
    if ((node->index + 1) < (node->arr->size())) {
      Triplet *newNode = new Triplet(node->index + 1, node->arr);
      pq.push(newNode);
    }
    delete node;
  }
  return ans;
}
*/
int main() {
    int k;
    cin >> k;

    vector<vector<int> *> input;

    for (int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current->push_back(a);
        }

        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    return 0;
}
