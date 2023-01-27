/*
Q. Second Largest Element In Tree

Given a generic tree, find and return the node with second largest value in given tree.

Note: Return NULL if no node with required value is present.

Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output Format :
The first and only line of output contains data of the node with second largest data.

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 

Sample Output 1 :
40

*/

#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

template<typename T>
class Large{
public:
  TreeNode<T>* fLarge;
  TreeNode<T>* sLarge;
  Large(){
    fLarge = NULL;
    sLarge = NULL;
  }
};

Large<int> *secondLargeNode(TreeNode<int>* root){
  if(root == NULL){
    Large<int>* n = new Large<int>();
    return n;
  }
  Large<int>* ans = new Large<int>();
  ans -> fLarge = root;

  for(int i = 0; i < root -> children.size(); i++){
    Large<int>* tmp = secondLargeNode(root -> children[i]);
    TreeNode<int>* dVal = NULL;
    if(tmp -> fLarge -> data > ans -> fLarge -> data){
      dVal = ans -> fLarge;
      ans -> fLarge = tmp -> fLarge;
    }else if((tmp -> fLarge -> data != ans -> fLarge -> data) && ans -> sLarge == NULL){
      ans -> sLarge = tmp -> fLarge;
    }
    if(dVal != NULL && (tmp -> fLarge -> data < ans -> fLarge -> data) && (dVal -> data < tmp -> fLarge -> data)){
      ans -> sLarge = tmp -> fLarge;
    }else if(dVal != NULL && tmp -> sLarge != NULL && (tmp -> sLarge -> data < ans -> fLarge -> data) && (dVal -> data < tmp -> sLarge -> data)){
      ans -> sLarge = tmp -> sLarge;
    }else if(dVal != NULL){
      ans -> sLarge = dVal;
    }
  }
  return ans;
}
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    return secondLargeNode(root) -> sLarge;
}

/*
#include <climits>

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    TreeNode<int> *fLargeNode = NULL, *sLargeNode = NULL;
    int fLargeNum = INT_MIN, sLargeNum = INT_MIN;

    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        if(front -> data > fLargeNum){
            sLargeNum = fLargeNum;
            sLargeNode = fLargeNode;
            fLargeNum = front -> data;
            fLargeNode = front;
        }else if(front -> data < fLargeNum && front -> data > sLargeNum){
            sLargeNum = front -> data;
            sLargeNode = front;
        }
        for(int i = 0; i < front -> children.size(); i++){
            pendingNodes.push(front -> children[i]);
        }
    }
    return sLargeNode;
}
*/

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }

}
