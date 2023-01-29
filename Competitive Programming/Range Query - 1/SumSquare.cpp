#include<iostream>
using namespace std;
#define int long long int
#define endl '\n'

struct tNode{
  int sqSum;
  int sum;
};

void buildTree(int *arr, tNode *tree, int start, int end, int treeNode){
  if(start == end){
    tree[treeNode].sqSum = arr[start]*arr[start];
    tree[treeNode].sum = arr[start];
    return;
  }
  int mid = (start+end)/2;
  buildTree(arr, tree, start, mid, 2*treeNode+1);
  buildTree(arr, tree, mid+1, end, 2*treeNode+2);
  tree[treeNode].sqSum = tree[2*treeNode+1].sqSum + tree[2*treeNode+2].sqSum;
  tree[treeNode].sum = tree[2*treeNode+1].sum + tree[2*treeNode+2].sum;
}

void updateTreeIncrement(tNode *tree, int *lazy, int start, int end, int left, int right, int currPos, int value){
  if(start > end){
    return;
  }

  if(lazy[currPos] != 0){
    value += lazy[currPos];
    if(start != end){
      lazy[2*currPos+1] = value;
      lazy[2*currPos+2] = value;
    }
    lazy[currPos] = 0;
    tree[currPos].sqSum += ((2*value) * tree[currPos].sum)+ ((value*value) * (end-start+1));
    tree[currPos].sum += value * (end-start+1);
  }

  if(start > end || left > end || right < start){
    return;
  }

  if(left <= start && right >= end){
    tree[currPos].sqSum += ((2*value) * tree[currPos].sum)+ ((value*value) * (end-start+1));
    tree[currPos].sum += value * (end-start+1);
    if(start != end){
      lazy[2*currPos+1] = value;
      lazy[2*currPos+2] = value;
    }
    return;
  }

  int mid = (start+end)/2;
  updateTreeIncrement(tree, lazy, start, mid, left, right, 2*currPos+1, value);
  updateTreeIncrement(tree, lazy, mid+1, end, left, right, 2*currPos+2, value);
  tree[currPos].sqSum = tree[2*currPos+1].sqSum + tree[2*currPos+2].sqSum;
  tree[currPos].sum = tree[2*currPos+1].sum + tree[2*currPos+2].sum;
}

void updateTreeChange(tNode *tree, int *lazy, int start, int end, int left, int right, int currPos, int value){
  if(start > end){
    return;
  }

  if(lazy[currPos] != 0){
    value = lazy[currPos];
    if(start != end){
      lazy[2*currPos+1] = value;
      lazy[2*currPos+2] = value;
    }
    lazy[currPos] = 0;
    tree[currPos].sqSum = (value*value) * (end-start+1);
    tree[currPos].sum = value * (end-start+1);
  }

  if(start > end || left > end || right < start){
    return;
  }

  if(left <= start && right >= end){
    tree[currPos].sqSum = (value*value) * (end-start+1);
    tree[currPos].sum = value * (end-start+1);
    if(start != end){
      lazy[2*currPos+1] = value;
      lazy[2*currPos+2] = value;
    }
    return;
  }
  int mid = (start+end)/2;
  updateTreeChange(tree, lazy, start, mid, left, right, 2*currPos+1, value);
  updateTreeChange(tree, lazy, mid+1, end, left, right, 2*currPos+2, value);
  tree[currPos].sqSum = tree[2*currPos+1].sqSum + tree[2*currPos+2].sqSum;
  tree[currPos].sum = tree[2*currPos+1].sum + tree[2*currPos+2].sum;
}

int query(tNode *tree, int *lazy, int start, int end, int treeNode, int left, int right){
  if(start > end){
    return 0;
  }
  if(lazy[treeNode] != 0){
    int value = lazy[treeNode];
    if(start != end){
      lazy[2*treeNode+1] = value;
      lazy[2*treeNode+2] = value;
    }
    lazy[treeNode] = 0;
    tree[treeNode].sqSum += (value*value) * (end-start+1);
    tree[treeNode].sum += value * (end-start+1);
  }
  //Completely outside of given Range
  if(start > right || end < left){
    return 0;
  }
  //Completely inside of given Range
  if(start >= left && end <= right){
    return tree[treeNode].sqSum;
  }
  //Partially inside and Partially outside of given Range
  int mid = (start+end)/2;
  int ans1 = query(tree, lazy, start, mid, 2*treeNode+1, left, right);
  int ans2 = query(tree, lazy, mid+1, end, 2*treeNode+2, left, right);
  return ans1+ans2;
}
int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int l;
  cin >> l;
  while(l--){
    int n, t;
    cin >> n >> t;
    int *arr = new int[n];
    tNode *tree = new tNode[4*n]();
    int *lazy = new int[4*n]();

    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }
    buildTree(arr, tree, 0, n-1, 0);
    /*
    for(int i = 0; i < 4*n; i++){
      cout << tree[i].sqSum << " - " << tree[i].sum << endl;
    }
  */
    while(t--){
      int a, i, j, x;
      cin >> a;
      if(a == 0){
        cin >> i >> j >> x;
        updateTreeChange(tree, lazy, 0, n-1, i-1, j-1, 0, x);
      }else if(a == 1){
        cin >> i >> j >> x;
        updateTreeIncrement(tree, lazy, 0, n-1, i-1, j-1, 0, x);
      }else if(a == 2){
        cin >> i >> j;
        int ans = query(tree, lazy, 0, n-1, 0, i-1, j-1);
        cout << ans << endl;
      }
    }
    /*
    for(int i = 0; i < 4*n; i++){
      cout << tree[i].sqSum << " - " << tree[i].sum << endl;
    }
    */
    delete [] arr;
    delete [] tree;
    delete [] lazy;
  }
  return 0;
}
