#include <iostream>
#include <queue>
#include <cmath>
#include <climits>
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

class IsBSTReturn{
public:
  bool isBST;
  int minimum;
  int maximum;
};

IsBSTReturn isBSTHelper(BinaryTreeNode<int>* root){
  if(root == NULL){
    IsBSTReturn output;
    output.isBST = true;
    output.minimum = INT_MAX;
    output.maximum = INT_MIN;
    return output;
  }
  IsBSTReturn leftOutput = isBSTHelper(root -> left);
  IsBSTReturn rightOutput = isBSTHelper(root -> right);
  int minimum = min(root -> data, min(leftOutput.minimum, rightOutput.minimum));
  int maximum = max(root -> data, max(leftOutput.maximum, rightOutput.maximum));
  bool isBSTFinal = (root -> data > leftOutput.maximum) && (root -> data <= rightOutput.minimum) && leftOutput.isBST && rightOutput.isBST;

  IsBSTReturn output;
  output.isBST = isBSTFinal;
  output.minimum = minimum;
  output.maximum = maximum;
  return output;
}

bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
  IsBSTReturn output = isBSTHelper(root);
  return output.isBST;
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
    cout << (isBST(root) ? "true" : "false");
}
