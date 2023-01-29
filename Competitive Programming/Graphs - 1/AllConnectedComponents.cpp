#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void dfs(int **edges, int n, int sv, bool *visited, vector<int> *v){
  v -> push_back(sv);
  visited[sv] = true;
  for(int i = 1; i <= n; i++){
    if(i != sv && edges[sv][i] == 1 && !visited[i]){
      dfs(edges, n, i, visited, v);
    }
  }
}

void bfs(int **edges, int n, int sv, bool *visited, vector<int> *v){
  queue<int> q;
  q.push(sv);
  visited[sv] = true;
  while(!q.empty()){
    int front = q.front();
    q.pop();
    v -> push_back(front);
    for(int i = 1; i <= n; i++){
      if(i != front && edges[front][i] == 1 && !visited[i]){
        q.push(i);
        visited[i] = true;
      }
    }
  }
}

void connectedComponents(int **edges, int n){
  bool *visited = new bool[n+1];
  for(int i = 0; i <= n; i++){
    visited[i] = false;
  }
  for(int i = 1; i <= n; i++){
    if(!visited[i]){
      vector<int> *v = new vector<int>();
      //dfs(edges, n, i, visited, v);
      bfs(edges, n, i, visited, v);
      sort(v -> begin(), v -> end());
      for(int i = 0; i < v -> size(); i++){
        cout << v -> at(i) << " ";
      }
      cout << endl;
      delete v;
    }
  }
  delete [] visited;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, e;
    cin >> n >> e;
    int **edges = new int*[n+1];
    for(int i = 0; i <= n; i++){
      edges[i] = new int[n+1];
      for(int j = 0; j <= n; j++){
        edges[i][j] = 0;
      }
    }

    for(int i = 0; i < e; i++){
      int f, s;
      cin >> f >> s;
      edges[f][s] = 1;
      edges[s][f] = 1;
    }
    connectedComponents(edges,n);
    for(int i = 0; i <= n; i++){
      delete [] edges[i];
    }
    delete [] edges;
  }
}
