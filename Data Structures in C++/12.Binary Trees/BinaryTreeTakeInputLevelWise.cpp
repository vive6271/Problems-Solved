#include<iostream>
#include "BinaryTreeNode.h"
#include<queue>
using namespace std;

BinaryTreeNode<int> *takeInputLevelWise(){
  int rootData;
  cout << "Enter Root Data : ";
  cin >> rootData;
  if(rootData == -1){
    return NULL;
  }
  BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
  queue<BinaryTreeNode<int>*> pendingNodes;
  pendingNodes.push(root);

  while(pendingNodes.size() != 0){
    BinaryTreeNode<int>* front = pendingNodes.front();
    pendingNodes.pop();
    cout << "Enter Left Child Data of " << front -> data << " : ";
    int leftChild;
    cin >> leftChild;
    if(leftChild != -1){
      BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChild);
      front -> left = child;
      pendingNodes.push(child);
    }
    cout << "Enter Right Child Data of " << front -> data << " : ";
    int rightChild;
    cin >> rightChild;
    if(rightChild != -1){
      BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChild);
      front -> right = child;
      pendingNodes.push(child);
    }
  }
  return root;
}

void printBinaryTree(BinaryTreeNode<int>* root){
  if(root == NULL){
    return;
  }
  cout << root -> data << " : ";
  if(root -> left != NULL){
    cout << "L" << root -> left -> data << " ";
  }
  if(root -> right != NULL){
    cout << "R" << root -> right -> data;
  }
  cout << endl;
  printBinaryTree(root -> left);
  printBinaryTree(root -> right);
}

int main(){
  BinaryTreeNode<int>* root = takeInputLevelWise();
  printBinaryTree(root);
}
