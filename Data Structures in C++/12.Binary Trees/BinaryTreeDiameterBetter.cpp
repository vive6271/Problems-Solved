#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


pair<int, int> heightDiameter(BinaryTreeNode<int>* root){
  if(root == NULL){
    pair<int, int> p;
    p.first = 0;
    p.second = 0;
    return p;
  }

  pair<int, int> leftAns = heightDiameter(root -> left);
  pair<int, int> rightAns = heightDiameter(root -> right);
  int ld = leftAns.second;
  int lh = leftAns.first;
  int rd = rightAns.second;
  int rh = rightAns.first;

  int height = 1+max(lh,rh);
  int diameter = max(lh+rh, max(ld,rd));
  pair<int, int> p;
  p.first = height;
  p.second = diameter;
  return p;
}

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

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    pair<int, int> p = heightDiameter(root);
    cout << "Height : " << p.first << endl;
    cout << "Diameter : " << p.second << endl;
    return 0;
}
