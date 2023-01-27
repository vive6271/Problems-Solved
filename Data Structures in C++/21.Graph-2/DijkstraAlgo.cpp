#include<bits/stdc++.h>
using namespace std;

int getMinVertex(bool *visited, int *dist, int n){
  int minVertex = -1;
  for(int i = 0; i < n; i++){
    if(!visited[i] && ((minVertex == -1) || dist[minVertex] > dist[i])){
      minVertex = i;
    }
  }
  return minVertex;
}

void dijkstraAlgo(int **edges, int n){
  bool *visited = new bool[n];
  int *dist = new int[n];
  for(int i = 0; i < n; i++){
    visited[i] = false;
    dist[i] = INT_MAX;
  }
  dist[0] = 0;

  for(int i = 0; i < n-1; i++){
    int minVertex = getMinVertex(visited, dist, n);
    visited[minVertex] = true;
    for(int j = 0; j < n; j++){
      if(!visited[j] && edges[minVertex][j] != 0){
        int newDist = dist[minVertex] + edges[minVertex][j];
        if(dist[j] > newDist){
          dist[j] = newDist;
        }
      }
    }
  }

  for(int i = 0; i < n; i++){
    cout << i << " " << dist[i] << endl;
  }
  delete [] visited;
  delete [] dist;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, e;
    cin >> n >> e;

    int **edges = new int*[n];
    for(int i = 0; i < n; i++){
      edges[i] = new int[n];
      for(int j = 0; j < n; j++){
        edges[i][j] = 0;
      }
    }

    int f, s, w;
    for(int i = 0; i < e; i++){
      cin >> f >> s >> w;
      edges[f][s] = w;
      edges[s][f] = w;
    }
    dijkstraAlgo(edges,n);
    for(int i = 0; i < n; i++){
      delete [] edges[i];
    }
    delete [] edges;
  }
  return 0;
}
