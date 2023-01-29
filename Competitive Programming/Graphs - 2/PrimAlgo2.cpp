#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
int INF = 1e9;

int getMinVertex(bool *visited, int *weight, int n){
  int minVertex = -1;
  for(int i = 0; i < n; i++){
    if(!visited[i] && ((minVertex == -1) || weight[minVertex] > weight[i])){
      minVertex = i;
    }
  }
  return minVertex;
}

int primAlgo(int **edges, int n){
  bool *visited = new bool[n];
  int *parent = new int[n];
  int *weight = new int[n];

  for(int i = 0; i < n; i++){
    visited[i] = false;
    weight[i] = INT_MAX;
  }
  parent[0] = -1;
  weight[0] = 0;

  for(int i = 0; i < n-1; i++){
    int minVertex = getMinVertex(visited, weight, n);
    visited[minVertex] = true;
    for(int j = 0; j < n; j++){
      if(edges[minVertex][j] != INF && !visited[j]){
        if(weight[j] > edges[minVertex][j]){
          weight[j] = edges[minVertex][j];
          parent[j] = minVertex;
        }
      }
    }
  }
  int totalWeight = 0;
  for(int i = 1; i < n; i++){
    totalWeight += weight[i];
  }
  delete [] visited;
  delete [] parent;
  delete [] weight;

  return totalWeight;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, e;
    cin >> n >> e;
    int **edges = new int*[n];
    for(int i = 0; i < n; i++){
      edges[i] = new int[n];
      for(int j = 0; j < n; j++){
        edges[i][j] = INF;
      }
    }

    int f, s, w;
    for(int i = 0; i < e; i++){
      cin >> f >> s >> w;
      edges[f][s] = min(edges[f][s], w);
      edges[s][f] = min(edges[s][f], w);
    }

    cout << primAlgo(edges,n) << endl;

    for(int i = 0; i < n; i++){
      delete [] edges[i];
    }
    delete [] edges;
  }
  return 0;
}
