#include<iostream>
#include<climits>
using namespace std;

void buildTree(int *arr, int *tree, int start, int end, int treeNode){
  if(start == end){
    tree[treeNode] = arr[start];
    return;
  }
  int mid = (start+end) / 2;
  buildTree(arr, tree, start, mid, 2*treeNode+1);
  buildTree(arr, tree, mid+1, end, (2*treeNode)+2);
  tree[treeNode] = min(tree[2*treeNode+1], tree[(2*treeNode)+2]);
}

void updateSegmentTreeLazy(int *tree, int *lazy, int low, int high, int startR, int endR, int currPos, int inc){
  if(low > high){
    return;
  }

  if(lazy[currPos] != 0){
    tree[currPos] += lazy[currPos];
    if(low != high){
      lazy[2*currPos+1] += lazy[currPos];
      lazy[2*currPos+2] += lazy[currPos];
    }
    lazy[currPos] = 0;
  }

  //No Overlap
  if(startR > high || endR < low){
    return;
  }

  //Complete Overlap
  if(startR <= low && endR >= high){
    tree[currPos] += inc;
    if(low != high){
      lazy[2*currPos+1] += inc;
      lazy[2*currPos+2] += inc;
    }
    return;
  }

  //Partially Overlap

  int mid = (low+high)/2;
  updateSegmentTreeLazy(tree, lazy, low, mid, startR, endR, 2*currPos+1, inc);
  updateSegmentTreeLazy(tree, lazy, mid+1, high, startR, endR, 2*currPos+2, inc);
  tree[currPos] = min(tree[2*currPos+1], tree[2*currPos+2]);

}

int query(int *tree, int *lazy, int start, int end, int treeNode, int left, int right){
  //Completely outside of given Range
  if(start > right || end < left){
    return INT_MAX;
  }
  //Completely inside of given Range
  if(start >= left && end <= right){
    if(lazy[treeNode] != 0){
      tree[treeNode] += lazy[treeNode];
      lazy[treeNode] = 0;
    }
    return tree[treeNode];
  }
  //Partially inside and Partially outside of given Range
  int mid = (start+end)/2;
  int ans1 = query(tree, lazy, start, mid, 2*treeNode+1, left, right);
  int ans2 = query(tree, lazy, mid+1, end, 2*treeNode+2, left, right);
  return min(ans1,ans2);
}

int main(){
  int n, t;
  cin >> n;
  int *arr = new int[n];
  int *tree = new int[4*n];
  int *lazy = new int[4*n]();
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  buildTree(arr, tree, 0, n-1, 0);
  cin >> t;
  while(t--){
    char ch;
    int r1, r2, inc;
    cin >> ch;
    cout << "Range : ";
    cin >> r1 >> r2;
    if(ch == 'U'){
      cout << "Increment By : ";
      cin >> inc;
      updateSegmentTreeLazy(tree, lazy, 0, n-1, r1, r2, 0, inc);
    }else if(ch == 'Q'){
      int ans = query(tree, lazy, 0, n-1, 0, r1, r2);
      cout << ans << endl;
    }
  }
  cout << "Segment Tree : ";
  for(int i = 0; i < 4*n; i++){
    cout << tree[i] << " ";
  }
  cout << endl;
  cout << "Lazy Tree : ";
  for(int i = 0;i < 4*n; i++){
    cout << lazy[i] << " ";
  }
  cout << endl;
  delete [] arr;
  delete [] tree;
  delete [] lazy;
  return 0;
}
