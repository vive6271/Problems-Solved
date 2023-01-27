#include<iostream>
#include "BinaryTreeNode.h"
using namespace std;

void printBinaryTree(BinaryTreeNode<int>* root){
  //Note :- In Case of Binary Tree Base Case is required
  if(root == NULL){
    return;
  }
  cout << root -> data << endl;
  printBinaryTree(root -> left);
  printBinaryTree(root -> right);
}


void printBinaryTree2(BinaryTreeNode<int>* root){
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
  printBinaryTree2(root -> left);
  printBinaryTree2(root -> right);
}

int main(){
  BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
  BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
  BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
  root -> left = node1;
  root -> right = node2;
  printBinaryTree(root);
  printBinaryTree2(root);
  return 0;
}
