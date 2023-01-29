#include<iostream>
#define endl '\n'
using namespace std;

struct Node{
  int odd = 0;
  int even = 0;
};

void buildTree(int *arr, Node *tree, int start, int end, int treeNode){
  if(start == end){
    if(arr[start] % 2 == 0){
      tree[treeNode].even = 1;
    }else{
      tree[treeNode].odd = 1;
    }
    return;
  }

  int mid = (start+end)/2, newTreeNode1 = 2*treeNode+1, newTreeNode2 = 2*treeNode+2;
  buildTree(arr, tree, start, mid, newTreeNode1);
  buildTree(arr, tree, mid+1, end, newTreeNode2);
  tree[treeNode].odd = tree[newTreeNode1].odd + tree[newTreeNode2].odd;
  tree[treeNode].even = tree[newTreeNode1].even + tree[newTreeNode2].even;
}

void updateTree(int *arr, Node *tree, int start, int end, int treeNode, int index, int value){
  if(start == end){
    arr[index] = value;
    if(value % 2 == 0){
      tree[treeNode].odd = 0;
      tree[treeNode].even = 1;
    }else{
      tree[treeNode].odd = 1;
      tree[treeNode].even = 0;
    }
    return;
  }

  int mid = (start+end)/2, newTreeNode1 = 2*treeNode+1, newTreeNode2 = 2*treeNode+2;
  if(index <= mid){
    updateTree(arr, tree, start, mid, newTreeNode1, index, value);
  }else{
    updateTree(arr, tree, mid+1, end, newTreeNode2, index, value);
  }
  tree[treeNode].odd = tree[newTreeNode1].odd + tree[newTreeNode2].odd;
  tree[treeNode].even = tree[newTreeNode1].even + tree[newTreeNode2].even;
}

Node query(Node *tree, int start, int end, int treeNode, int left, int right){
  if(start > right || end < left){
    Node n;
    n.odd = 0;
    n.even = 0;
    return n;
  }

  if(start >= left && end <= right){
    return tree[treeNode];
  }

  int mid = (start+end)/2;
  Node n1 = query(tree, start, mid, 2*treeNode+1, left, right);
  Node n2 = query(tree, mid+1, end, 2*treeNode+2, left, right);

  Node ans;
  ans.odd = n1.odd + n2.odd;
  ans.even = n1.even + n2.even;
  return ans;
}

int main(){
  int n, q;
  cin >> n;
  int *arr = new int[n];
  Node *tree = new Node[4*n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  buildTree(arr, tree, 0, n-1, 0);
  cin >> q;
  while(q--){
    int a, x, y;
    cin >> a >> x >> y;
    if(a == 0){
      updateTree(arr, tree, 0, n-1, 0, x-1, y);
    }else if(a == 1){
      Node ans = query(tree, 0, n-1, 0, x-1, y-1);
      cout << ans.even << endl;
    }else if(a == 2){
      Node ans = query(tree, 0, n-1, 0, x-1, y-1);
      cout << ans.odd << endl;
    }
  }
  delete [] arr;
  delete [] tree;
  return 0;
}
