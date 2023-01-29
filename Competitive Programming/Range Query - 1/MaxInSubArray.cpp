#include<iostream>
#include<climits>
#define endl '\n'
using namespace std;

void buildTree(int *arr, int *tree, int start, int end, int treeNode){
  if(start == end){
    tree[treeNode] = arr[start];
    return;
  }

  int mid = (start+end)/2, newTreeNode1 = 2*treeNode+1, newTreeNode2 = 2*treeNode+2;
  buildTree(arr, tree, start, mid, newTreeNode1);
  buildTree(arr, tree, mid+1, end, newTreeNode2);
  tree[treeNode] = max(tree[newTreeNode1], tree[newTreeNode2]);
}

int query(int *tree, int treeNode, int start, int end, int left, int right){
  if(start > right || end < left){
    return INT_MIN;
  }

  if(start >= left && end <= right){
    return tree[treeNode];
  }

  int mid = (start+end)/2;
  int ans1 = query(tree, 2*treeNode+1, start, mid, left, right);
  int ans2 = query(tree, 2*treeNode+2, mid+1, end, left, right);
  return max(ans1,ans2);
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, q;
  cin >> n;
  int *arr = new int[n];
  int *tree = new int[4*n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  buildTree(arr, tree, 0, n-1, 0);
  cin >> q;
  while(q--){
    int l, r;
    cin >> l >>r;
    int ans = query(tree, 0, 0, n-1, l, r);
    cout << ans << endl;
  }
  delete [] arr;
  delete [] tree;
  return 0;
}
