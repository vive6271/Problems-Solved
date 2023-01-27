/*
Q. Check if a Binary Tree is BST

Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.

Note: Duplicate elements should be kept in the right subtree.

Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output format :
The first and only line of output contains either true or false.

Sample Input 1 :
3 1 5 -1 2 -1 -1 -1 -1

Sample Output 1 :
true

Sample Input 2 :
5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1

Sample Output 2 :
false
*/

#include <iostream>
#include <queue>
#include <climits>
#include <cmath>
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

pair<bool, pair<int, int>> isBSTHelper(BinaryTreeNode<int> *root){
  if(root == NULL){
    pair<bool, pair<int, int>> output;
    output.first = true;
    output.second.first = INT_MAX;
    output.second.second = INT_MIN;
    return output;
  }
  pair<bool, pair<int, int>> leftOutput = isBSTHelper(root -> left);
  pair<bool, pair<int, int>> rightOutput = isBSTHelper(root -> right);

  int minimum = min(root -> data, min(leftOutput.second.first, rightOutput.second.first));
  int maximum = max(root -> data, max(leftOutput.second.second, rightOutput.second.second));
  bool isBSTFinal = (root -> data > leftOutput.second.second) && (root -> data <= rightOutput.second.first) && leftOutput.first && rightOutput.first;

  pair<bool, pair<int, int>> output;
  output.first = isBSTFinal;
  output.second.first = minimum;
  output.second.second = maximum;
  return output;
}
bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
  pair<bool, pair<int, int>> output = isBSTHelper(root);
  return output.first;
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
    cout << (isBST(root) ? "true" : "false");
}
