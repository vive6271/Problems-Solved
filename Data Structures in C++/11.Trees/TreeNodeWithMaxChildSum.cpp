/*
Q. Node with maximum child sum

Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. 
In the sum, data of the node and data of its immediate child nodes has to be taken.

Input format :
The first line of input contains data of the nodes of the tree in level order form. 
The order is: data for root node, number of children to root node, data of each of child nodes 
and so on and so forth for each node. The data of the nodes of the tree is separated by space. 

Output format :
The first and only line of output contains the data of the node with maximum sum, as described in the task.

Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0

Sample Output 1 :
1
*/

#include <iostream>
#include <queue>
#include <vector>
#include<climits>
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
class MaxNodePair{
public:
  T maxSum;
  TreeNode<T>* maxNode;
};

MaxNodePair<int>* maxNodeSumHelper(TreeNode<int>* root){
  if(root == NULL){
    MaxNodePair<int>* pair = new MaxNodePair<int>();
    pair -> maxSum = INT_MIN;
    pair -> maxNode = NULL;
    return pair;
  }

  int sum = root -> data;
  for(int i = 0; i < root -> children.size(); i++){
    sum += root -> children[i] ->  data;
  }
  MaxNodePair<int>* ans = new MaxNodePair<int>();
  ans -> maxSum = sum;
  ans -> maxNode = root;

  for(int i = 0; i < root -> children.size(); i++){
    MaxNodePair<int>* childAns = maxNodeSumHelper(root -> children[i]);
    if(ans -> maxSum <= childAns -> maxSum){
      ans = childAns;
    }
  }
  return ans;
}
TreeNode<int>* maxSumNode(TreeNode<int>* root) {
  return maxNodeSumHelper(root) -> maxNode;
}

/*

Best

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    if(!root){
        return NULL;
    }
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    TreeNode<int>* maxNode = NULL;
    int maxSum = 0;
    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int currSum = front -> data;
        for(int i = 0; i < front -> children.size(); i++){
            currSum += front -> children[i] -> data;
            pendingNodes.push(front -> children[i]);
        }
        if(maxSum < currSum){
            maxSum = currSum;
            maxNode = front;
        }
    }
    return maxNode;
}
//-----------------------------------------------------------------------------------------------//
OR

int sumChild(TreeNode<int>* root){
  if(root == NULL){
    return 0;
  }
  int sum = root -> data;
  for(int i = 0; i < root -> children.size(); i++){
    sum += root -> children[i] -> data;
  }
  return sum;
}
TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code
    if(root == NULL){
      return root;
    }
    TreeNode<int>* ans = root;
    int rootSum = sumChild(root);

    for(int i = 0; i < root -> children.size(); i++){
      TreeNode<int>* tmp = maxSumNode(root -> children[i]);
      int tmpSum = sumChild(tmp);
      if(rootSum <= tmpSum){
        ans = tmp;
        rootSum = tmpSum;
      }
    }
    return ans;
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

    TreeNode<int>* ans = maxSumNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
}
