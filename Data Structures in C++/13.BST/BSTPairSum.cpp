/*
Q. Pair sum in a BST

Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space of the order of O(log n).
Note:
1. Assume BST contains all unique elements.
2. In a pair, print the smaller element first.

Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12

Sample Output 1:
2 10
5 7
*/

#include <iostream>
#include <queue>
#include <stack>
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

    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};


int countNodes(BinaryTreeNode<int> *root){
  if (root == NULL){
     return 0;
   }
   return countNodes(root->left) + countNodes(root->right) + 1;
 }
void leftMin(BinaryTreeNode<int>* root, stack<BinaryTreeNode<int>*> *stack){
  if(root == NULL){
    return;
  }
  stack -> push(root);
  leftMin(root -> left, stack);
}

void rightMax(BinaryTreeNode<int>* root, stack<BinaryTreeNode<int>*> *stack){
  if(root == NULL){
    return;
  }
  stack -> push(root);
  rightMax(root -> right, stack);
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
    if(root == NULL){
      return;
    }
    stack<BinaryTreeNode<int>*> *InStack = new stack<BinaryTreeNode<int>*>();
    stack<BinaryTreeNode<int>*> *revInStack = new stack<BinaryTreeNode<int>*>();
    int totalCount = countNodes(root);
    leftMin(root,InStack);
    rightMax(root,revInStack);

    int count = 0;
    while(count < totalCount-1){
      if(InStack -> top() -> data + revInStack -> top() -> data == s){
        BinaryTreeNode<int>* tmp1 = InStack -> top();
        BinaryTreeNode<int>* tmp2 = revInStack -> top();
        cout << tmp1 -> data << " " << tmp2 -> data << endl;
        InStack -> pop();
        revInStack -> pop();
        count += 2;
        leftMin(tmp1 -> right, InStack);
        rightMax(tmp2 -> left, revInStack);
      }else if(InStack -> top() -> data + revInStack -> top() -> data > s){
        BinaryTreeNode<int>* tmp = revInStack -> top();
        revInStack -> pop();
        count++;
        rightMax(tmp -> left, revInStack);
      }else{
        BinaryTreeNode<int>* tmp = InStack -> top();
        InStack -> pop();
        count++;
        leftMin(tmp -> right, InStack);
      }
    }
    delete InStack;
    delete revInStack;

/*
    cout << "InStack" << endl;
    while(!InStack -> empty()){
      cout << InStack -> top() -> data<< " ";
      InStack -> pop();
    }
    cout << "\nRevInStack" << endl;
    while(!revInStack -> empty()){
      cout << revInStack -> top() -> data << " ";
      revInStack -> pop();
    }
*/

}
/*
int countNodes(BinaryTreeNode<int> *root){
  if (root == NULL){
     return 0;
   }
   return countNodes(root->left) + countNodes(root->right) + 1;
 }
 void printNodesSumToS(BinaryTreeNode<int> *root, int s){
   if (root == NULL){
     return;
   }
   int totalCount = countNodes(root);
   int count = 0;
   stack<BinaryTreeNode<int> *> inorder;
   stack<BinaryTreeNode<int> *> revInorder;
   BinaryTreeNode<int> *currentNode = root;
   while (currentNode != NULL) {
      inorder.push(currentNode);
      currentNode = currentNode->left;
  }
  currentNode = root;
  while (currentNode != NULL) {
    revInorder.push(currentNode);
    currentNode = currentNode->right;
  }
  while (count < totalCount - 1){
   BinaryTreeNode<int> *inorderTop = inorder.top();
   BinaryTreeNode<int> *revInorderTop = revInorder.top();
   if (inorderTop->data + revInorderTop->data == s) {
     cout << inorderTop->data << " " << revInorderTop->data << endl;
     BinaryTreeNode<int> *top = inorderTop;
     inorder.pop();
     count++;
     if (top->right != NULL){
       top = top->right;
       while (top != NULL){
        inorder.push(top);
        top = top->left;
      }
    }
    top = revInorderTop;
    revInorder.pop();
    count++;
    if (top->left != NULL) {
      top = top->left;
      while (top != NULL) {
        revInorder.push(top);
        top = top->right;
      }
    }
  } else if (inorderTop->data + revInorderTop->data > s) {
     BinaryTreeNode<int> *top = revInorderTop;
     revInorder.pop();
     count++;
     if (top->left != NULL) {
       top = top->left;
       while (top != NULL) {
         revInorder.push(top);
         top = top->right;
       }
     }
   } else {
     BinaryTreeNode<int> *top = inorderTop;
     inorder.pop();
     count++;
     if (top->right != NULL) {
       top = top->right;
       while (top != NULL) {
         inorder.push(top);
         top = top->left;
       }
     }
   }
 }
}
*/
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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
}
