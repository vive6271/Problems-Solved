#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

class trieNode{
public:
  trieNode* left;
  trieNode* right;
};

void insert(int n, trieNode* head){
  trieNode* currentNode = head;
  for(int i = 31; i >= 0; i--){
    int b = (n >> i) & 1;
    if(b == 0){
      if(!currentNode -> left){
        currentNode -> left = new trieNode();
      }
      currentNode = currentNode -> left;
    }else{
      if(!currentNode -> right){
        currentNode -> right = new trieNode();
      }
      currentNode = currentNode -> right;
    }
  }
}

int findMaxXorPair(trieNode* head, int* arr, int n){
  int maxXor = INT_MIN;
  for(int i = 0; i < n; i++){
    int value = arr[i];
    trieNode* currentNode = head;
    int currXor = 0;
    for(int j = 31; j >= 0; j--){
      int b = (value >> j) & 1;
      if(b == 0){
        if(currentNode -> right){
          currXor += (1 << j);
          currentNode = currentNode -> right;
        }else{
          currentNode = currentNode -> left;
        }
      }else{
        if(currentNode -> left){
          currXor += (1 << j);
          currentNode = currentNode -> left;
        }else{
          currentNode = currentNode -> right;
        }
      }
    }
    if(currXor > maxXor){
      maxXor = currXor;
    }
  }
  return maxXor;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  int* arr = new int[n];
  trieNode* head = new trieNode();
  for(int i = 0; i < n; i++){
    cin >> arr[i];
    insert(arr[i], head);
  }
  cout << findMaxXorPair(head, arr, n) << endl;
  delete [] arr;
  return 0;
}
