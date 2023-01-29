#include<iostream>
using namespace std;
#define MOD 3
#define endl '\n'


/*
Note :- pow of 2^n % 3 for odd num = 2 and even num = 1. so its not needed

#define N 100001
int pow[N];

void power(){
  int num = 1;
  for(int i = 0; i < N; i++){
    pow[i] = num;
    num = (2*num) % MOD;
  }
}
*/
int power(int n){
  if(n & 1 == 1){
    return 2;
  }
  return 1;
}

void buildTree(char *arr, int *tree, int start, int end, int treeNode){
  if(start == end){
    if(arr[start] == '1'){
      tree[treeNode] = 1;
    }else{
      tree[treeNode] = 0;
    }
    return;
  }
  int mid = (start+end)/2, newTreeNode1 = 2*treeNode+1, newTreeNode2 = 2*treeNode+2;
  buildTree(arr, tree, start, mid, newTreeNode1);
  buildTree(arr, tree, mid+1, end, newTreeNode2);
  tree[treeNode] = (((tree[newTreeNode1] * power(end-mid)) % MOD ) + (tree[newTreeNode2] % MOD)) % MOD;
}

void updateTree(char *arr, int *tree, int treeNode, int start, int end, int index){
  if(start == end){
    arr[index] = '1';
    tree[treeNode] = 1;
    return;
  }

  int mid = (start+end)/2, newTreeNode1 = 2*treeNode+1, newTreeNode2 = 2*treeNode+2;
  if(index <= mid){
    updateTree(arr, tree, newTreeNode1, start, mid, index);
  }else{
    updateTree(arr, tree, newTreeNode2, mid+1, end, index);
  }
  tree[treeNode] = (((tree[newTreeNode1] * power(end-mid)) % MOD ) + (tree[newTreeNode2] % MOD)) % MOD;
}

int query(int *tree, int treeNode, int start, int end, int left, int right){
  if(start > right || end < left){
    return 0;
  }
  if(start >= left && end <= right){
    return (tree[treeNode] * power(end-right)) % MOD;
  }
  int mid = (start+end)/2;
  int n1 = query(tree, 2*treeNode+1, start, mid, left, right);
  int n2 = query(tree, 2*treeNode+2, mid+1, end, left, right);
  return (n1 + n2) % MOD;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, q;
  cin >> n;
  char *arr = new char[n];
  int *tree = new int[4*n];
  cin >> arr;
  //power();
  buildTree(arr, tree, 0, n-1, 0);
  cin >> q;
  while(q--){
    int a, l, r;
    cin >> a;
    if(a == 0){
      cin >> l >> r;
      int ans = query(tree, 0, 0, n-1, l, r);
      cout << ans << endl;
    }else if(a == 1){
      cin >> l;
      updateTree(arr, tree, 0, 0, n-1, l);
    }
  }
  delete [] arr;
  delete [] tree;
  return 0;
}
