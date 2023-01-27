/*
Q. Level order traversal

For a given a Binary Tree of type integer, print it in a level order fashion where each level will be printed on a new line. Elements on every level will be printed in a linear fashion and a single space will separate them.

Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will separate them.

Sample Input 1:
10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1 

Sample Output 1:
10 
20 30 
40 50 60 

Sample Input 2:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

Sample Output 2:
8 
3 10 
1 6 14 
4 7 13 
*/

#include <iostream>
#include <queue>

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

using namespace std;
void printLevelWise(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL){
      return;
    }

    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
      BinaryTreeNode<int>* front = q.front();
      q.pop();
      if(front == NULL){
        if(q.empty()){
          break;
        }
        cout << endl;
        q.push(NULL);
        continue;
      }
      cout << front -> data << " ";
      if(front -> left != NULL){
        q.push(front -> left);
      }
      if(front -> right != NULL){
        q.push(front -> right);
      }
    }
}

/*
void printLevelWise(BinaryTreeNode<int> *root) {
    // Write your code here
	if(!root){
		return;
	}
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	pendingNodes.push(NULL);
	while(!pendingNodes.empty()){
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << front -> data << " ";
		if(front -> left){
			pendingNodes.push(front -> left);
		}
		if(front -> right){
			pendingNodes.push(front -> right);
		}
		if(pendingNodes.front() == NULL){
			pendingNodes.pop();
			if(!pendingNodes.empty()){
				pendingNodes.push(NULL);
				cout << endl;
			}
		}
	}
}
*/

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
    printLevelWise(root);
}
