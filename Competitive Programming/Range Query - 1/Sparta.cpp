#include<iostream>
#define endl '\n'

using namespace std;

struct Warrior{
  int strength;
  int cowardice;
};

bool isBest(Warrior w1, Warrior w2){
  if((w1.strength > w2.strength) || ((w1.strength == w2.strength) && (w1.cowardice <= w2.cowardice))){
    return true;
  }
  return false;
}
void buildTree(Warrior *arr, int *tree, int start, int end, int treeNode){
  if(start == end){
    tree[treeNode] = start;
    return;
  }
  int mid = (start+end)/2, newTreeNode1 = 2*treeNode+1, newTreeNode2 = 2*treeNode+2;
  buildTree(arr, tree, start, mid, newTreeNode1);
  buildTree(arr, tree, mid+1, end, newTreeNode2);
  int index1 = tree[newTreeNode1], index2 = tree[newTreeNode2];
  if(isBest(arr[index1], arr[index2])){
    tree[treeNode] = index1;
  }else{
    tree[treeNode] = index2;
  }
}

int query(Warrior *arr, int *tree, int start, int end, int treeNode, int left, int right){
  if(start > right || end < left){
    return -1;
  }

  if(start >= left && end <= right){
    return tree[treeNode];
  }

  int mid = (start+end)/2;
  int index1 = query(arr, tree, start, mid, 2*treeNode+1, left, right);
  int index2 = query(arr, tree, mid+1, end, 2*treeNode+2, left, right);
  if(index1 == -1 || index2 == -1){
    return max(index1, index2);
  }
  if(isBest(arr[index1], arr[index2])){
    return index1;
  }
  return index2;
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, q;
  cin >> n;
  Warrior *arr = new Warrior[n];
  int *tree = new int[4*n];
  for(int i = 0; i < n; i++){
    cin >> arr[i].strength;
  }
  for(int i = 0; i < n; i++){
    cin >> arr[i].cowardice;
  }
  buildTree(arr, tree, 0, n-1, 0);
  cin >> q;
  while(q--){
    int l, r;
    cin >> l >> r;
    int ans = query(arr, tree, 0, n-1, 0, l-1, r-1);
    cout << ans+1 << endl;
  }
  delete [] arr;
  delete [] tree;
  return 0;
}
