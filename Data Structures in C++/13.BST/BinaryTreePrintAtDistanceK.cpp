/*
Q. Print nodes at distance k from node

You are given a Binary Tree of type integer, a target node, and an integer value K.
Print the data of all nodes that have a distance K from the target node. The order in which they would be printed will not matter.

Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
3 1

Sample Output 1:
9
6

Sample Input 2:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
3 3

Sample Output 2:
4
5
*/

#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
    	if(left)
       		delete left;
    	if(right)
       		delete right;
    }
};


void printAtDistance(BinaryTreeNode<int> *root, int k){
  if(root == NULL){
    return;
  }
  if(k == 0){
    cout << root -> data << endl;
    return;
  }
  printAtDistance(root -> left, k-1);
  printAtDistance(root -> right, k-1);
}

int nodesAtDistanceKHelper(BinaryTreeNode<int>* root, int node, int k){
  if(root == NULL){
    return -1;
  }
  if(root -> data == node){
    printAtDistance(root,k);
    return 0;
  }
  int leftDistance = nodesAtDistanceKHelper(root -> left, node, k);
  if(leftDistance != -1){
    if(leftDistance + 1 == k){
      cout << root -> data << endl;
    }else{
      printAtDistance(root -> right, (k - leftDistance -2));
    }
    return leftDistance+1;
  }
  int rightDistance = nodesAtDistanceKHelper(root -> right, node, k);
  if(rightDistance != -1){
    if(rightDistance + 1 == k){
      cout << root -> data << endl;
    }else{
      printAtDistance(root -> left, (k - rightDistance -2));
    }
    return rightDistance+1;
  }
  return -1;
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code herez
    int n = nodesAtDistanceKHelper(root,node,k);
}

BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}
