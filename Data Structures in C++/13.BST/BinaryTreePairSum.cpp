/*
Q. Pair Sum Binary Tree

Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.

Note:
1. Assume the given binary tree contains all unique elements.
2. In a pair, print the smaller element first. Order of different pairs doesn't matter.

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
15

Sample Output 1:
5 10
6 9
*/

#include <iostream>
#include <queue>
#include<algorithm>
#include<vector>
template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

void pairSumHelper(BinaryTreeNode<int> *root, vector<int> *v){
  if(root == NULL){
    return;
  }
  v -> push_back(root -> data);
  pairSumHelper(root -> left, v);
  pairSumHelper(root -> right, v);
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    vector<int> *v = new vector<int>();
    pairSumHelper(root,v);
    sort( v -> begin(), v -> end());
    int start = 0, end = v -> size() - 1;
    while(start < end){
      int vSum = v -> at(start) + v -> at(end);
      if(vSum == sum){
        cout << v -> at(start) << " " << v -> at(end) << endl;
        start++;
        end--;
      }else if(vSum < sum){
        start++;
      }else{
        end--;
      }
    }
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}
