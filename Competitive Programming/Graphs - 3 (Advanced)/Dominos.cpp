#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void dfs(vector<int>* edges, int start, bool* visited, stack<int> &finishStack, bool reverse){
  visited[start] = true;
  for(int i = 0; i < edges[start].size(); i++){
    int adjacent = edges[start][i];
    if(!visited[adjacent]){
      dfs(edges, adjacent, visited, finishStack, reverse);
    }
  }
  if(reverse){
    finishStack.push(start);
  }
}

int dominos(vector<int> *edges, int n){
  bool *visited = new bool[n]();
  stack<int> finishedVertices;
  for(int i = 0; i < n; i++){
    if(!visited[i]){
      dfs(edges, i, visited, finishedVertices, true);
    }
  }
  int count = 0;
  memset(visited, false, n);
  while(!finishedVertices.empty()){
    int element = finishedVertices.top();
    finishedVertices.pop();
    if(!visited[element]){
      dfs(edges, element, visited, finishedVertices, false);
      count++;
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
    int n, m;
    cin >> n >> m;
    vector<int> *edges = new vector<int>[n];
    for(int i = 0; i < m; i++){
      int x, y;
      cin >> x >> y;
      edges[x-1].push_back(y-1);
    }
    cout << dominos(edges, n) << endl;
    delete [] edges;
  }
  return 0;
}
