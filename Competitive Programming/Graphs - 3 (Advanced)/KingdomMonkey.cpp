#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void dfs(vector<int> *edges, int start, bool *visited, unordered_set<int> &component){
  visited[start] = true;
  component.insert(start);
  for(int i = 0; i < edges[start].size(); i++){
    int next = edges[start][i];
    if(!visited[next]){
      dfs(edges, next, visited, component);
    }
  }
}

int countCoin(vector<int>* edges, int* coin, int n){
  bool *visited = new bool[n]();
  int count = 0;
  for(int i = 0; i < n; i++){
    if(!visited[i]){
      unordered_set<int> component;
      dfs(edges, i, visited, component);
      unordered_set<int> :: iterator it = component.begin();
      int tmp = 0;
      while(it != component.end()){
        tmp += coin[*it];
        it++;
      }
      count = max(count, tmp);
    }
  }
  delete [] visited;
  return count;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, m, x, y;
    cin >> n >> m;
    vector<int> *edges = new vector<int>[n];
    int *coin = new int[n];
    for(int i = 0; i < m; i++){
      cin >> x >> y;
      edges[x-1].push_back(y-1);
      edges[y-1].push_back(x-1);
    }
    for(int i = 0; i < n; i++){
      cin >> coin[i];
    }
    cout << countCoin(edges, coin, n) << endl;
    delete [] edges;
    delete [] coin;
  }
  return 0;
}
