#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

class trieNode{
public:
  trieNode** children;
  bool leafNode;
  trieNode(){
    children = new trieNode*[26];
    for(int i = 0; i < 26; i++){
      children[i] = NULL;
    }
    leafNode = false;
  }
  ~trieNode(){
    for(int i = 0; i < 26; i++){
      if(children[i] != NULL){
        delete children[i];
      }
    }
    delete [] children;
  }
};

void insert(trieNode* root, string str){
  if(str.empty()){
    root -> leafNode = true;
    return;
  }
  int idx = str[0] - 'a';
  trieNode* child;
  if(root -> children[idx]){
    child = root -> children[idx];
  }else{
    child = new trieNode();
    root -> children[idx] = child;
  }
  insert(child, str.substr(1));
}

void dfsPrint(trieNode* root, string str){
  if(root -> leafNode){
    cout << str << endl;
  }
  for(int i = 0; i < 26; i++){
    char ch = 'a' +1;
    if(root -> children[i]){
      dfsPrint(root -> children[i], str + ch);
    }
  }
}

bool autoComplete(trieNode* root, string str){
  trieNode* currentNode = root;
  for(int i = 0; i < str.length(); i++){
    int idx = str[i] - 'a';
    trieNode* child = currentNode -> children[idx];
    if(child){

      currentNode = child;
    }else{
      return false;
    }
  }
  dfsPrint(currentNode, str);
  return true;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, q;
  cin >> n;
  string str;
  trieNode* head = new trieNode();
  //Insert
  for(int i = 0; i < n; i++){
    cin >> str;
    insert(head, str);
  }

  //Query
  cin >> q;
  for(int i = 0; i < q; i++){
    cin >> str;
    if(!autoComplete(head, str)){
      cout << "No suggestions" << endl;
      insert(head, str);
    }
  }
  return 0;
}
