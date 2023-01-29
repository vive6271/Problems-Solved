#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

class trieNode{
public:
  trieNode* left;
  trieNode* right;
  int leftCount = 0;
  int rightCount = 0;
};

void insert(trieNode* head, int n){
  trieNode* currentNode = head;
  for(int i = 31; i >= 0; i--){
    int b = (n >> i) & 1;
    if(b == 0){
      if(!currentNode -> left){
        currentNode -> left = new trieNode();
      }
      currentNode -> leftCount++;
      currentNode = currentNode -> left;
    }else{
      if(!currentNode -> right){
        currentNode -> right = new trieNode();
      }
      currentNode -> rightCount++;
      currentNode = currentNode -> right;
    }
  }
}

int findMaxXorSubArray(trieNode* head, int n, int k){
  if(head == NULL){
    return 0;
  }
  int count = 0;
  trieNode* currentNode = head;
  for(int i = 31; i >= 0; i--){
    int a = (n >> i) & 1;
    int b = (k >> i) & 1;
    if(a == 1 && b == 1){
      count += currentNode -> rightCount;
      if(!currentNode -> left){
        return count;
      }
      currentNode = currentNode -> left;
    }else if(a == 1 && b == 0){
      if(!currentNode -> right){
        return count;
      }
      currentNode = currentNode -> right;
    }else if(a == 0 && b == 1){
      count += currentNode -> leftCount;
      if(!currentNode -> right){
        return count;
      }
      currentNode = currentNode -> right;
    }else if(a == 0 && b == 0){
      if(!currentNode -> left){
        return count;
      }
      currentNode = currentNode -> left;
    }
  }
  return count;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k, x;
  cin >> n >> k;
  trieNode* head = new trieNode();
  int arrXor = 0, count = 0;
  insert(head, arrXor);
  for(int i = 0; i < n; i++){
    cin >> x;
    arrXor ^= x;
    count += findMaxXorSubArray(head, arrXor, k);
    insert(head, arrXor);
  }
  cout << count << endl;
  return 0;
}
