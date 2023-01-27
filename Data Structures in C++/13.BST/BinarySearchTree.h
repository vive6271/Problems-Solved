#include "BinaryTreeNode.h"
#include <queue>
using namespace std;
class BST{
  BinaryTreeNode<int>* root;

public:
  BST(){
    root = NULL;
  }

  ~BST(){
    delete root;
  }

  void deleteData(int data){
    this -> root = deleteData(data,root);
  }

  void insertData(int data){
    this -> root = insertData(data,root);
  }

  bool hasData(int data){
    return hasData(data,root);
  }
  void printLevelWise(){
    printLevelWise(root);
  }
private:
  bool hasData(int data, BinaryTreeNode<int>* node){
    if(node == NULL){
      return false;
    }

    if(node -> data == data){
      return true;
    }else if(node -> data > data){
      return hasData(data, node -> left);
    }else{
      return hasData(data, node -> right);
    }
  }

  BinaryTreeNode<int>* insertData(int data, BinaryTreeNode<int>* node){
    if(node == NULL){
      BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
      return newNode;
    }

    if(node -> data > data){
      node -> left = insertData(data, node -> left);
    }else{
      node -> right = insertData(data, node -> right);
    }
    return node;
  }

  BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int>* node){
    if(node == NULL){
      return NULL;
    }
    if(node -> data < data){
      node -> right = deleteData(data, node -> right);
    }else if(node -> data > data){
      node -> left = deleteData(data, node -> left);
    }else{
      if(node -> left == NULL && node -> right == NULL){
        delete node;
        return NULL;
      }else if(node -> left == NULL){
        BinaryTreeNode<int>* tmpNode = node -> right;
        node -> right = NULL;
        delete node;
        return tmpNode;
      }else if(node -> right == NULL){
        BinaryTreeNode<int>* tmpNode = node -> left;
        node -> left = NULL;
        delete node;
        return tmpNode;
      }else{
        BinaryTreeNode<int>* minNode = node -> right;
        while(minNode -> left != NULL){
          minNode = minNode -> left;
        }
        int rightMin = minNode -> data;
        node -> data = rightMin;
        node -> right = deleteData(rightMin, node -> right);
        return node;
      }
    }
  }
  void printLevelWise(BinaryTreeNode<int>* node) {
    if(node == NULL){
      return;
    }
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(node);

    while(pendingNodes.size() != 0){
      BinaryTreeNode<int>* front = pendingNodes.front();
      cout << front -> data << ":";
      pendingNodes.pop();
      if(front -> left != NULL){
        cout << "L:" << front -> left -> data << ",";
        pendingNodes.push(front -> left);
      }else{
        cout << "L:-1,";
      }
      if(front -> right != NULL){
        cout << "R:" << front -> right -> data;
        pendingNodes.push(front -> right);
      }else{
        cout << "R:-1";
      }
      cout << endl;
    }
  }
};
