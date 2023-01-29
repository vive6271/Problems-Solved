#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>* edges, int start, unordered_set<int>* component, bool *visited){
  visited[start] = true;
  component -> insert(start);
  for(int i = 0; i < edges[start].size(); i++){
    int next = edges[start][i];
    if(!visited[next]){
      dfs(edges, next, component, visited);
    }
  }
}

unordered_set<unordered_set<int>*>* getComponents(vector<int>* edges, int n){
  bool *visited = new bool[n]();
  unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
  for(int i = 0; i < n; i++){
    if(!visited[i]){
      unordered_set<int>* component = new unordered_set<int>();
      dfs(edges, i, component, visited);
      output -> insert(component);
    }
  }
  delete visited;
  return output;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;

    int* p = new int[n];
    int* q = new int[n];
    for(int i = 0; i < n; i++){
      cin >> p[i];
    }
    for(int i = 0; i < n; i++){
      cin >> q[i];
    }
    vector<int> *edges = new vector<int>[n];
    for(int i = 0; i < m; i++){
      int x, y;
      cin >> x >> y;
      edges[x-1].push_back(y-1);
      edges[y-1].push_back(x-1);
    }

    unordered_set<unordered_set<int>*>* components = getComponents(edges, n);
  	unordered_set<unordered_set<int>*>::iterator it1 = components->begin();
    bool isPossible = true;
  	while (it1 != components->end()) {
  		unordered_set<int>* component = *it1;
  		unordered_set<int>::iterator it2 = component->begin();
      unordered_set<int> a, b;
  		while (it2 != component->end()){
        a.insert(p[*it2]);
        b.insert(q[*it2]);
        it2++;
      }
      if(a != b){
        isPossible = false;
        while (it1 != components -> end()){
          delete *it1;
          it1++;
        }
        break;
      }
      delete component;
      it1++;
    }
    if(isPossible){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
    delete components;
    delete [] p;
    delete [] q;
    delete [] edges;
  }
  return 0;
}
