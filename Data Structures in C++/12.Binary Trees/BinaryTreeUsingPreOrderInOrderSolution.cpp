#include <iostream>
#include <queue>
using namespace std;

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

BinaryTreeNode<int>* buildTreeHelper(int *inOrder, int *preOrder, int inStart, int inEnd, int preStart, int preEnd){
  if(inStart > inEnd){
    return NULL;
  }
  int rootData = preOrder[preStart];
  int rootIndex = -1;
  for(int i = inStart; i <= inEnd; i++){
    if(inOrder[i] == rootData){
      rootIndex = i;
      break;
    }
  }

  int lInStart = inStart;
  int lInEnd = rootIndex-1;
  int lPreStart = preStart+1;
  int lPreEnd = lInEnd - lInStart + lPreStart;
  int rPreStart = lPreEnd+1;
  int rPreEnd = preEnd;
  int rInStart = rootIndex+1;
  int rInEnd = inEnd;

  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
  root -> left = buildTreeHelper(inOrder, preOrder, lInStart, lInEnd, lPreStart, lPreEnd);
  root -> right = buildTreeHelper(inOrder, preOrder, rInStart, rInEnd, rPreStart, rPreEnd);
  return root;
}

BinaryTreeNode<int>* buildTree(int *inOrder, int *preOrder, int size){
  return buildTreeHelper(inOrder, preOrder, 0, size-1, 0, size-1);
}

void printLevelWise(BinaryTreeNode<int> *root) {
	// Write your code here
  if(root == NULL){
    return;
  }
  queue<BinaryTreeNode<int>*> pendingNodes;
  pendingNodes.push(root);

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

int main() {
  int n, inOrder[10], preOrder[10];
  cout << "Enter Size of array : " ;
  cin >> n;

  cout << "*** Enter PreOrder Array ***" << endl;
  for(int i = 0; i < n; i++){
    cin >> preOrder[i];
  }
  cout << "*** Enter InOrder Array ***" << endl;
  for(int i = 0; i < n; i++){
    cin >> inOrder[i];
  }
  BinaryTreeNode<int>* root = buildTree(inOrder, preOrder, n);
  printLevelWise(root);
}
