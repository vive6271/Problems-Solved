#include<iostream>
#include<climits>
using namespace std;

struct Node{
  int Max;
  int sMax;
};

void buildTree(int *arr, Node *tree, int treeNode, int start, int end){
  if(start == end){
    tree[treeNode].Max = arr[start];
    tree[treeNode].sMax = INT_MIN;
    return;
  }

  int mid = (start+end)/2;
  buildTree(arr, tree, 2*treeNode+1, start, mid);
  buildTree(arr, tree, 2*treeNode+2, mid+1, end);

  Node left = tree[2*treeNode+1], right = tree[2*treeNode+2];
  tree[treeNode].Max = max(left.Max, right.Max);
  tree[treeNode].sMax = min(max(left.Max, right.sMax), max(left.sMax, right.Max));
}

void updateTree(int *arr, Node *tree, int treeNode, int start, int end, int index, int value){
  if(start == end){
    arr[index] = value;
    tree[treeNode].Max = value;
    return;
  }

  int mid = (start+end)/2, newTreeNode1 = 2*treeNode+1, newTreeNode2 = 2*treeNode+2;
  if(index <= mid){
    updateTree(arr, tree, newTreeNode1, start, mid, index, value);
  }else{
    updateTree(arr, tree, newTreeNode2, mid+1, end, index, value);
  }
  Node left = tree[newTreeNode1], right = tree[newTreeNode2];
  tree[treeNode].Max = max(left.Max, right.Max);
  tree[treeNode].sMax = min(max(left.Max, right.sMax), max(left.sMax, right.Max));
}

Node query(Node *tree, int treeNode, int start, int end, int left, int right){
  //Completely outside of given range
  if(start > right || end < left){
    Node p;
    p.Max = INT_MIN;
    p.sMax = INT_MIN;
    return p;
  }
  //Completely inside of given range
  if(start >= left && end <= right){
    return tree[treeNode];
  }
  //Partially outside and partially inside of given range
  int mid = (start+end)/2;
  Node n1, n2, ans;
  n1 = query(tree, 2*treeNode+1, start, mid, left, right);
  n2 = query(tree, 2*treeNode+2, mid+1, end, left, right);
  ans.Max = max(n1.Max, n2.Max);
  ans.sMax = min(max(n1.Max, n2.sMax), max(n1.sMax, n2.Max));
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
    char ch;
    int i, j;
    cin >> ch >> i >> j;
    if(ch == 'Q'){
      //Query
      Node ans = query(tree, 0, 0, n-1, i-1, j-1);
      if(ans.sMax == INT_MIN){
        cout << "-1" << endl;
      }else{
        cout << (ans.Max + ans.sMax) << endl;
      }
    }else if(ch == 'U'){
      //Update
      updateTree(arr, tree, 0, 0, n-1, i-1, j);
    }
  }
  delete [] arr;
  delete [] tree;
  return 0;
}
