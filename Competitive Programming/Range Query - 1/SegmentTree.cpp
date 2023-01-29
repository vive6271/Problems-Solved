#include<iostream>
using namespace std;

void buildTree(int *arr, int *tree, int start, int end, int treeNode){
  if(start == end){
    tree[treeNode] = arr[start];
    return;
  }
  int mid = (start+end) / 2;
  buildTree(arr, tree, start, mid, 2*treeNode);
  buildTree(arr, tree, mid+1, end, (2*treeNode)+1);
  tree[treeNode] = tree[2*treeNode] + tree[(2*treeNode)+1];
}

void updateTree(int *arr, int *tree, int start, int end, int treeNode, int index, int value){
  if(start == end){
    arr[index] = value;
    tree[treeNode] = value;
    return;
  }

  int mid = (start+end) / 2;
  if(index > mid){
    updateTree(arr, tree, mid+1, end, (2*treeNode)+1, index, value);
  }else{
    updateTree(arr, tree, start, mid, 2*treeNode, index, value);
  }
  tree[treeNode] = tree[2*treeNode] + tree[(2*treeNode)+1];
}

int query(int *tree, int start, int end, int treeNode, int left, int right){
  //Completely outside of given range
  if(start > right || end < left){
    return 0;
  }
  //Completely inside of given range
  if(start >= left && end <= right){
    return tree[treeNode];
  }
  //Partially outside and partially inside of given range
  int mid = (start+end)/2;
  int ans1 = query(tree, start, mid, 2*treeNode, left, right);
  int ans2 = query(tree, mid+1, end, 2*treeNode+1, left, right);
  return ans1 + ans2;
}

int main(){
  int n;
  cin >> n;
  int *arr = new int[n];
  int *tree = new int[2*n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  //Range
  int r1, r2;
  cin >> r1 >> r2;
  buildTree(arr, tree, r1, r2, 1);
  for(int i = 1; i < 2*n; i++){
    cout << tree[i] << " ";
  }
  cout << endl;
  //Update
  int index, value;
  cin >> index >> value;
  updateTree(arr, tree, r1, r2, 1, index, value);
  for(int i = 1; i < 2*n; i++){
    cout << tree[i] << " ";
  }
  cout << endl;
  //Query
  int q1, q2;
  cin >> q1 >> q2;
  int ans = query(tree, r1, r2, 1, q1, q2);
  cout << "Ans : " << ans << endl;
  delete [] arr;
  delete [] tree;
}
