#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void dfs(vector<int>* edges, int start, bool* visited){
  visited[start] = true;
  for(int i = 0; i < edges[start].size(); i++){
    int next = edges[start][i];
    if(!visited[next]){
      dfs(edges, next, visited);
    }
  }
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, x, q;
    cin >> n;
    vector<int> *edges = new vector<int>[n+1];
    for(int i = 1; i < n; i++){
      cin >> x;
      edges[i].push_back(i+x);
    }

    bool *visited = new bool[n+1]();
    dfs(edges, 1, visited);
    cin >> q;
    for(int i = 0; i < q; i++){
      cin >> x;
      if(visited[x]){
        cout << "YES" << endl;
      }else{
        cout << "NO" << endl;
      }
    }
    delete [] edges;
    delete [] visited;
  }
  return 0;
}
