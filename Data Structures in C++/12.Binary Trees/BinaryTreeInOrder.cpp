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

void printInOrder(BinaryTreeNode<int>* root){
  if(root == NULL){
    return;
  }
  printInOrder(root -> left);
  cout << root -> data << " ";
  printInOrder(root -> right);
}

int main(){
  BinaryTreeNode<int>* root = takeInputLevelWise();
  printInOrder(root);
  return 0;
}
