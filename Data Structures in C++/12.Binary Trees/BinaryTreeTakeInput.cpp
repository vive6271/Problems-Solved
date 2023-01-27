#include<iostream>
#include "BinaryTreeNode.h"
using namespace std;


void printBinaryTree(BinaryTreeNode<int>* root){
  //Note :- In Case of Binary Tree Base Case is required
  if(root == NULL){
    return;
  }
  cout << root -> data << " : ";
  //Or we can use if(root -> left)
  if(root -> left != NULL){
    cout << "L" << root -> left -> data << " ";
  }
  if(root -> right != NULL){
    cout << "R" << root -> right -> data << " ";
  }
  cout << endl;
  printBinaryTree(root -> left);
  printBinaryTree(root -> right);
}

BinaryTreeNode<int>* takeInput(){
  int rootData;
  cout << "Enter Data : ";
  cin >> rootData;
  if(rootData == -1){
    return NULL;
  }

  BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
  BinaryTreeNode<int>* leftChild = takeInput();
  BinaryTreeNode<int>* rightChild = takeInput();
  root -> left = leftChild;
  root -> right = rightChild;
  return root;
}
int main(){
  BinaryTreeNode<int>* root = takeInput();
  printBinaryTree(root);
  return 0;
}
