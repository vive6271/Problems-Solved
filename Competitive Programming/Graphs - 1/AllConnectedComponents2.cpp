#include <bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>> &adj, int index, bool visited[], vector<int> &compo){
  compo.push_back(index);
  visited[index] = true;
  for (auto v : adj[index]){
    if (visited[v] == false){
      dfs(adj, v, visited, compo);
    }
  }
}

int main(){
  int t;
  cin >> t;
  while (t--){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++){
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    bool visited[n + 1];
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++){
      if (visited[i] == false){
        vector<int> compo;
        dfs(adj, i, visited, compo);
        sort(compo.begin(), compo.end());
        for (int j = 0; j < compo.size(); j++){
          cout << compo[j] << " ";
        }
        cout << endl;
      }
    }
  }
  return 0;
}
