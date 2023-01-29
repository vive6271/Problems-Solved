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

bool solve(vector<int>* edges, int n, int* p, int*q){
  bool* visited = new bool[n]();
  for(int i = 0; i < n; i++){
    if(!visited[i]){
      unordered_set<int>* component = new unordered_set<int>();
      dfs(edges, i, component, visited);
      unordered_set<int> a, b;
      unordered_set<int> :: iterator it = component -> begin();
      while(it != component -> end()){
        a.insert(p[*it]);
        b.insert(q[*it]);
        it++;
      }
      delete component;
      if(a != b){
        return false;
      }
    }
  }
  return true;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;

    int *p = new int[n];
    int *q = new int[n];
    for(int i = 0; i < n; i++){
      cin >> p[i];
    }
    for(int i= 0; i < n; i++){
      cin >> q[i];
    }

    vector<int>* edges = new vector<int>[n];
    for(int i = 0; i < m; i++){
      int x, y;
      cin >> x >> y;
      edges[x-1].push_back(y-1);
      edges[y-1].push_back(x-1);
    }
    if(solve(edges, n, p, q)){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
    delete [] p;
    delete [] q;
    delete [] edges;
  }
  return 0;
}
