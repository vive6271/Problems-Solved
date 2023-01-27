/*
Q. Largest BST

Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 1:
2

*/

#include <iostream>
#include <queue>
#include<climits>
#include<cmath>
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
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

class BSTHeight{
public:
  int min;
  int max;
  bool isBST;
  int height;
};
using namespace std;

BSTHeight *BSTSubtreeHelper(BinaryTreeNode<int>* root){
  if(root == NULL){
    BSTHeight *output = new BSTHeight();
    output -> min = INT_MAX;
    output -> max = INT_MIN;
    output -> isBST = true;
    output -> height = 0;
    return output;
  }
  BSTHeight *leftOutput = BSTSubtreeHelper(root -> left);
  BSTHeight *rightOutput = BSTSubtreeHelper(root -> right);

  BSTHeight *output = new BSTHeight();
  output -> min = min(root -> data, min(leftOutput -> min, rightOutput -> min));
  output -> max = max(root -> data, max(leftOutput -> max, rightOutput -> max));
  output -> isBST = (root -> data > leftOutput -> max) && (root -> data < rightOutput -> min) && leftOutput -> isBST && rightOutput -> isBST;
  if(output -> isBST){
    output -> height = 1 + max(leftOutput -> height, rightOutput -> height);
  }else{
    output -> height = max(leftOutput -> height, rightOutput -> height);
  }
  return output;
}
int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
    BSTHeight *output = BSTSubtreeHelper(root);
    return output -> height;
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
    cout << largestBSTSubtree(root);
    delete root;
}
