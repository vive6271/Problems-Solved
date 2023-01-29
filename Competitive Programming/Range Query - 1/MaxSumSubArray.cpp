#include<iostream>
using namespace std;
#define MIN -10000

struct Node{
  int max_sum;
  int sum;
  int best_prefix_sum;
  int best_suffix_sum;
};

void buildTree(int *arr, Node *tree, int treeNode, int start, int end){
  if(start == end){
    tree[treeNode].max_sum = arr[start];
    tree[treeNode].sum = arr[start];
    tree[treeNode].best_prefix_sum = arr[start];
    tree[treeNode].best_suffix_sum = arr[start];
    return;
  }

  int mid = (start+end)/2, newTreeNode1 = 2*treeNode+1, newTreeNode2 = 2*treeNode+2;
  buildTree(arr, tree, newTreeNode1, start, mid);
  buildTree(arr, tree, newTreeNode2, mid+1, end);

  Node n1 = tree[newTreeNode1], n2 = tree[newTreeNode2];
  tree[treeNode].max_sum = max(max(max(n1.max_sum, n2.max_sum), max((n1.sum + n2.best_prefix_sum), (n2.sum + n1.best_suffix_sum))), (n1.best_suffix_sum + n2.best_prefix_sum));
  tree[treeNode].sum = (n1.sum + n2.sum);
  tree[treeNode].best_prefix_sum = max(n1.best_prefix_sum, (n1.sum + n2.best_prefix_sum));
  tree[treeNode].best_suffix_sum = max(n2.best_suffix_sum, (n2.sum + n1.best_suffix_sum));
}

Node query(Node *tree, int treeNode, int start, int end, int left, int right){
  //Completely outside of given range
  if(start > right || end < left){
    Node n;
    n.max_sum = MIN, n.sum = MIN, n.best_prefix_sum = MIN, n.best_suffix_sum = MIN;
    return n;
  }
  //Completely inside of given range
  if(start >= left && end <= right){
    return tree[treeNode];
  }
  //Partially outside and partially inside of given range
  int mid = (start+end)/2, newTreeNode1 = 2*treeNode+1, newTreeNode2 = 2*treeNode+2;
  Node n1, n2, ans;
  n1 = query(tree, newTreeNode1, start, mid, left, right);
  n2 = query(tree, newTreeNode2, mid+1, end, left, right);
  ans.max_sum = max(max(max(n1.max_sum, n2.max_sum), max((n1.sum + n2.best_prefix_sum), (n2.sum + n1.best_suffix_sum))), (n1.best_suffix_sum + n2.best_prefix_sum));
  ans.sum = (n1.sum + n2.sum);
  ans.best_prefix_sum = max(n1.best_prefix_sum, (n1.sum + n2.best_prefix_sum));
  ans.best_suffix_sum = max(n2.best_suffix_sum, (n2.sum + n1.best_suffix_sum));
  return ans;
}

int main(){
  int n, t;
  cin >> n;
  int *arr = new int[n];
  Node *tree = new Node[4*n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  buildTree(arr, tree, 0, 0, n-1);
  cin >> t;
  while(t--){
    int i, j;
    cin >> i >> j;
    Node ans = query(tree, 0, 0, n-1, i-1, j-1);
    cout << ans.max_sum << endl;
  }
  delete [] arr;
  delete [] tree;
  return 0;
}
