#include<iostream>
using namespace std;
#define endl '\n'
#define int long long int

void updateTree(int *tree, int *lazy, int start, int end, int left, int right, int treeNode, int value){
  if(start > end){
    return;
  }

  if(lazy[treeNode] != 0){
    tree[treeNode] += (end-start+1) * lazy[treeNode];
    if(start != end){
      lazy[2*treeNode+1] += lazy[treeNode];
      lazy[2*treeNode+2] += lazy[treeNode];
    }
    lazy[treeNode] = 0;
  }
  //No Overlap
  if(start > right || end < left){
    return;
  }

  //Complete Overlap
  if(start >= left && end <= right){
    tree[treeNode] += (end-start+1) * value;
    if(start != end){
      lazy[2*treeNode+1] += value;
      lazy[2*treeNode+2] += value;
    }
    return;
  }

  //Partially Overlap
  int mid = (start+end)/2;
  updateTree(tree, lazy, start, mid, left, right, 2*treeNode+1, value);
  updateTree(tree, lazy, mid+1, end, left, right, 2*treeNode+2, value);
  tree[treeNode] = tree[2*treeNode+1] + tree[2*treeNode+2];
}

int query(int *tree, int *lazy, int start, int end, int treeNode, int left, int right){
  if(start > end){
    return 0;
  }
  if(lazy[treeNode] != 0){
    tree[treeNode] += (end-start+1) * lazy[treeNode];
    if(start != end){
      lazy[2*treeNode+1] += lazy[treeNode];
      lazy[2*treeNode+2] += lazy[treeNode];
    }
    lazy[treeNode] = 0;
  }

  //Completely outside of given Range
  if(start > right || end < left){
    return 0;
  }

  //Completely inside of given Range
  if(start >= left && end <= right){
    return tree[treeNode];
  }

  //Partially inside and Partially outside of given Range
  int mid = (start+end)/2;
  int ans1 = query(tree, lazy, start, mid, 2*treeNode+1, left, right);
  int ans2 = query(tree, lazy, mid+1, end, 2*treeNode+2, left, right);
  return (ans1+ans2);
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, q;
    cin >> n;
    int *tree = new int[4*n]();
    int *lazy = new int[4*n]();

    cin >> q;
    while(q--){
      int a, p, q, v;
      cin >> a;
      if(a == 0){
        cin >> p >> q >> v;
        //Update
        updateTree(tree, lazy, 0, n-1, p-1, q-1, 0, v);
      }else if(a == 1){
        cin >> p >> q;
        //Query
        int ans = query(tree, lazy, 0, n-1, 0, p-1, q-1);
        cout << ans << endl;
      }
    }
/*
    for(int i = 0; i < 4*n; i++){
      //cout << tree[i] << " | " << lazy[i] << endl;
    }
*/
    delete [] tree;
    delete [] lazy;
  }
  return 0;
}
