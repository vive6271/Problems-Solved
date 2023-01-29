#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

class trieNode{
public:
  trieNode** children;
  int weight;

  trieNode(){
    children = new trieNode*[26];
    for(int i = 0; i < 26; i++){
      children[i] = NULL;
    }
    weight = 0;
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

void insert(string str, int weight, trieNode* root){
  if(str.empty()){
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
  if(child -> weight < weight){
    child -> weight = weight;
  }
  insert(str.substr(1), weight, child);
}

int searchBest(trieNode* root, string str){
  int bestWeight = -1;
  trieNode* currentNode = root;
  for(int i = 0; i < str.length(); i++){
    int idx = str[i] - 'a';
    trieNode* child = currentNode -> children[idx];
    if(child){
      bestWeight = child -> weight;
      currentNode = child;
    }else{
      return -1;
    }
  }
  return bestWeight;
}

vector<int>* searchEngine(vector<pair<string,int>> &database, vector<string> &text){
  //Inesrt
  trieNode* root = new trieNode();
  for(int i = 0; i < database.size(); i++){
    insert(database[i].first, database[i].second, root);
  }
  //Search
  vector<int> *output = new vector<int>();
  for(int i = 0; i < text.size(); i++){
    int ans = searchBest(root, text[i]);
    output -> push_back(ans);
  }
  return output;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, q, x;
  cin >> n >> q;
  vector<pair<string,int>> database;
  string str;
  for(int i = 0; i < n; i++){
    cin >> str >> x;
    database.push_back({str,x});
  }
  vector<string> text;
  for(int i = 0; i < q; i++){
    cin >> str;
    text.push_back(str);
  }
  vector<int>* output = searchEngine(database, text);
  for(int i = 0; i < output -> size(); i++){
    cout << output -> at(i) << endl;
  }
  delete output;
  return 0;
}
