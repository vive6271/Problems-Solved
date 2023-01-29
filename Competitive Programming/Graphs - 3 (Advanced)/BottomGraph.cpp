#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void dfs(vector<int>* edges, int start, bool* visited, stack<int> &finishStack){
  visited[start] = true;
  for(int i = 0; i < edges[start].size(); i++){
    int adjacent = edges[start][i];
    if(!visited[adjacent]){
      dfs(edges, adjacent, visited, finishStack);
    }
  }
  finishStack.push(start);
}

void dfs2(vector<int>* edges, int start, bool* visited, unordered_set<int> &component){
  visited[start] = true;
  component.insert(start);
  for(int i = 0; i < edges[start].size(); i++){
    int adjacent = edges[start][i];
    if(!visited[adjacent]){
      dfs2(edges, adjacent, visited, component);
    }
  }
}

void bottomGraph(vector<int>* edges, vector<int>* edgesT, int n){
  bool* visited = new bool[n]();
  stack<int> finishedVertices;
  for(int i = 0; i < n; i++){
    if(!visited[i]){
      dfs(edges, i, visited, finishedVertices);
    }
  }
  memset(visited, false, n);
  bool *ans = new bool[n];
  memset(ans, true, n);
  while(!finishedVertices.empty()){
    int element = finishedVertices.top();
    finishedVertices.pop();
    if(!visited[element]){
      unordered_set<int> component;
      dfs2(edgesT, element, visited, component);

      unordered_set<int> :: iterator it = component.begin();
      bool fConnect = true; //Fully Connected Component
      while(it != component.end()){
        int num = *it;
        for(int i = 0; i < edges[num].size(); i++){
          if(component.find(edges[num][i]) == component.end()){
            fConnect = false;
            break;
          }
        }
        if(!fConnect){
          break;
        }
        it++;
      }
      if(!fConnect){
        it = component.begin();
        while(it != component.end()){
          ans[*it] = false;
          it++;
        }
      }
    }
  }

  for(int i = 0; i < n; i++){
    if(ans[i]){
      cout << i+1 << " ";
    }
  }
  cout << endl;
  delete [] visited;
  delete [] ans;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;
    vector<int>* edges = new vector<int>[n];
    vector<int>* edgesT = new vector<int>[n];
    for(int i = 0; i < m; i++){
      int x, y;
      cin >> x >> y;
      edges[x-1].push_back(y-1);
      edgesT[y-1].push_back(x-1);
    }
    bottomGraph(edges, edgesT, n);
    delete [] edges;
    delete [] edgesT;
  }
  return 0;
}
