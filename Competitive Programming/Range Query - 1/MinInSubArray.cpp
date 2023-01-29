#include<bits/stdc++.h>
using namespace std;

void buildTree(int *arr, int *tree, int start, int end, int treeNode){
  if(start == end){
    tree[treeNode] = arr[start];
    return;
  }
  int mid = (start+end)/2;
  buildTree(arr, tree, start, mid, 2*treeNode+1);
  buildTree(arr, tree, mid+1, end, 2*treeNode+2);
  tree[treeNode] = min(tree[(2*treeNode)+1], tree[(2*treeNode)+2]);
}

void updateTree(int *arr, int* tree, int start, int end, int treeNode, int index, int value){
  if(start == end){
    arr[index] = value;
    tree[treeNode] = value;
    return;
  }
  int mid = (start+end)/2;
  if(index <= mid){
    updateTree(arr, tree, start, mid, 2*treeNode+1, index, value);
  }else{
    updateTree(arr, tree, mid+1, end, 2*treeNode+2, index, value);
  }
  tree[treeNode] = min(tree[(2*treeNode)+1], tree[(2*treeNode)+2]);
}

int query(int *tree, int start, int end, int treeNode, int left, int right){
  //Completely outside of given Range
  if(start > right || end < left){
    return INT_MAX;
  }
  //Completely inside of given Range
  if(start >= left && end <= right){
    return tree[treeNode];
  }
  //Partially inside and Partially outside of given Range
  int mid = (start+end)/2;
  int ans1 = query(tree, start, mid, 2*treeNode+1, left, right);
  int ans2 = query(tree, mid+1, end, 2*treeNode+2, left, right);
  return min(ans1,ans2);
}

int main(){
  int n, t;
  cin >> n >> t;
  int *arr = new int[n];
  int *tree = new int[4*n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  buildTree(arr, tree, 0, n-1, 0);
  while(t--){
    char ch;
    int i, j;
    cin >> ch >> i >> j;
    if(ch == 'q'){
      //Query
      int ans = query(tree, 0, n-1, 0, i-1, j-1);
      cout << ans << endl;
    }else if(ch == 'u'){
      //Update
      updateTree(arr, tree, 0, n-1, 0, i-1, j);
    }
  }
  delete [] arr;
  delete [] tree;
  return 0;
}
