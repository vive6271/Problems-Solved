/*
Q. Check Balanced

Given a binary tree, check if it is balanced. Return true if given binary tree is balanced, false otherwise.

Balanced Binary Tree:
A empty binary tree or binary tree with zero nodes is always balanced. For a non empty binary tree to be balanced, following conditions must be met:
1. The left and right subtrees must be balanced.
2. |hL - hR| <= 1, where hL is the height or depth of left subtree and hR is the height or depth of right subtree.    

Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output format
The first and only line of output contains true or false.

Sample Input 1 :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 1 :
false

Sample Input 2 :
1 2 3 -1 -1 -1 -1

Sample Output 2 :
true
*/

#include <iostream>
#include <queue>
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
};

using namespace std;
/*
int height(BinaryTreeNode<int>* root){
  if(root == NULL){
    return 0;
  }
  return 1+max(height(root -> left), height(root -> right));
}
bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
  if(root == NULL){
    return true;
  }
  bool leftAns = isBalanced(root -> left);
  int hLeft = height(root -> left);
  int hRight = height(root -> right);
  if(hLeft - hRight > 1 || hLeft - hRight < -1){
    return false;
  }
  bool rightAns = isBalanced(root -> right);
  return leftAns && rightAns;
}
*/

pair<bool, int> helperBalanced(BinaryTreeNode<int>* root){
  if(root == NULL){
    pair<bool, int> p;
    p.first = true;
    p.second = 0;
    return p;
  }
  pair<bool, int> leftAns = helperBalanced(root -> left);
  pair<bool, int> rightAns = helperBalanced(root -> right);
  pair<bool, int> ans;
  ans.second = 1+max(leftAns.second, rightAns.second);
  ans.first = leftAns.first && rightAns.first;
  if(((leftAns.second - rightAns.second > 1) || (leftAns.second - rightAns.second < -1))){
    ans.first = false;
  }
  return ans;
}

bool isBalanced(BinaryTreeNode<int> *root) {
  pair<bool, int> p = helperBalanced(root);
  return p.first;
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
    cout << (isBalanced(root) ? "true" : "false");
}
