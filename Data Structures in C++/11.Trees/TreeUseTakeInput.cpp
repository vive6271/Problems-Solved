#include<iostream>
#include "TreeNode.h" //Use to access local files
#include<queue>
using namespace std;


void printTree(TreeNode<int>* root){
  cout << root -> data << " : ";
  for(int i = 0; i < root -> children.size(); i++){
    cout << root -> children[i] -> data << " ";
  }
  cout << endl;
  for(int i = 0; i < root -> children.size(); i++){
    printTree(root -> children[i]);
  }
}

TreeNode<int>* takeInputLevelWise(){
  int rootData;
  cout << "Enter Root Data : ";
  cin >> rootData;
  TreeNode<int>* root = new TreeNode<int>(rootData);

  queue<TreeNode<int>*> pendingNodes;
  pendingNodes.push(root);
  while(pendingNodes.size() != 0){
    TreeNode<int>* front = pendingNodes.front();
    pendingNodes.pop();
    cout << "Enter number of children of " << front -> data << " : ";
    int numChild;
    cin >> numChild;
    for(int i = 0; i < numChild; i++){
      int childData;
      cout << "Enter " << i << "th child of " << front -> data << " : ";
      cin >> childData;
      TreeNode<int>* child = new TreeNode<int>(childData);
      front -> children.push_back(child);
      pendingNodes.push(child);
    }
  }
  return root;
}

TreeNode<int>* takeInput(){
  int rootData;
  cout << "Enter Data : ";
  cin >> rootData;
  TreeNode<int>* root = new TreeNode<int>(rootData);

  int n;
  cout << "Enter number of children of " << rootData << " : ";
  cin >> n;
  for(int i = 0; i < n; i++){
    TreeNode<int>* child = takeInput();
    root -> children.push_back(child);
  }
  return root;
}
int main(){
  //TreeNode<int>* root = takeInput();
  TreeNode<int>* root = takeInputLevelWise();

  printTree(root);
  // TODO delete the tree
  return 0;
}
