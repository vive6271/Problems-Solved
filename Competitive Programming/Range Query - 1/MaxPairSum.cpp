#include<bits/stdc++.h>
using namespace std;

void buildTree(int *arr, pair<int,int> *tree, int treeNode, int start, int end){
  if(start == end){
    tree[treeNode].first = INT_MIN;
    tree[treeNode].second = arr[start];
    return;
  }
  int mid = (start+end)/2, newTreeNode1 = 2*treeNode+1, newTreeNode2 = 2*treeNode+2;
  buildTree(arr, tree, newTreeNode1, start, mid);
  buildTree(arr, tree, newTreeNode2, mid+1, end);
  pair<int,int> p1 = tree[newTreeNode1], p2 = tree[newTreeNode2];
  tree[treeNode].first = min(max(p1.first, p2.second),max(p1.second, p2.first));
  tree[treeNode].second = max(max(p1.first, p2.second),max(p1.second, p2.first));
}

void updateTree(int *arr, pair<int,int> *tree, int treeNode, int start, int end, int index, int value){
  if(start == end){
    arr[index] = value;
    tree[treeNode].second = value;
    return;
  }

  int mid = (start+end)/2, newTreeNode1 = 2*treeNode+1, newTreeNode2 = 2*treeNode+2;
  if(index <= mid){
    updateTree(arr, tree, newTreeNode1, start, mid, index, value);
  }else{
    updateTree(arr, tree, newTreeNode2, mid+1, end, index, value);
  }
  pair<int,int> p1 = tree[newTreeNode1], p2 = tree[newTreeNode2];
  tree[treeNode].first = min(max(p1.first, p2.second),max(p1.second, p2.first));
  tree[treeNode].second = max(max(p1.first, p2.second),max(p1.second, p2.first));
}

pair<int,int> query(pair<int,int> *tree, int treeNode, int start, int end, int left, int right){
  //Completely outside of given range
  if(start > right || end < left){
    pair<int,int> p;
    p.first = INT_MIN;
    p.second = INT_MIN;
    return p;
  }
  //Completely inside of given range
  if(start >= left && end <= right){
    return tree[treeNode];
  }
  //Partially outside and partially inside of given range
  int mid = (start+end)/2;
  pair<int,int> p1, p2, ans;
  p1 = query(tree, 2*treeNode+1, start, mid, left, right);
  p2 = query(tree, 2*treeNode+2, mid+1, end, left, right);
  ans.first = min(max(p1.first, p2.second),max(p1.second, p2.first));
  ans.second = max(max(p1.first, p2.second),max(p1.second, p2.first));
  return ans;
}

int main(){
  int n, t;
  cin >> n;
  int *arr = new int[n];
  pair<int,int> *tree = new pair<int,int>[4*n];
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
      pair<int,int> ans = query(tree, 0, 0, n-1, i-1, j-1);
      if(ans.first == INT_MIN){
        cout << "-1" << endl;
      }else{
        cout << (ans.first + ans.second) << endl;
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
