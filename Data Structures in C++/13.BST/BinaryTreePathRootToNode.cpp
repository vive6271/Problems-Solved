#include <iostream>
#include <queue>
#include <vector>

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
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;

vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data){
  if(root == NULL){
    return NULL;
  }
  if(root -> data == data){
    vector<int>* output = new vector<int>();
    output -> push_back(root -> data);
    return output;
  }

  vector<int>* leftOutput = getRootToNodePath(root -> left, data);
  if(leftOutput != NULL){
    leftOutput -> push_back(root -> data);
    return leftOutput;
  }
  vector<int>* rightOutput = getRootToNodePath(root -> right, data);
  if(rightOutput != NULL){
    rightOutput -> push_back(root -> data);
    return rightOutput;
  }
  return NULL;
}

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int x;
    cout << "Enter element to find : ";
    cin >> x;
    vector<int>* output = getRootToNodePath(root,x);
    for(int i = output -> size()-1; i >= 0; i--){
      cout << output -> at(i) << " ";
    }
    cout << endl;
    delete output;
}
