#include<bits/stdc++.h>
using namespace std;

int getMinVertex(bool *visited, int *weight, int n){
  int minVertex = -1;
  for(int i = 0; i < n; i++){
    if(!visited[i] && ((minVertex == -1) || (weight[minVertex] > weight[i]))){
      minVertex = i;
    }
  }
  return minVertex;
}

void primAlgo(int **edges, int n){
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
      if(edges[minVertex][j] != 0 && !visited[j]){
        if(weight[j] > edges[minVertex][j]){
          weight[j] = edges[minVertex][j];
          parent[j] = minVertex;
        }
      }
    }
  }

  for(int i = 1; i < n; i++){
    if(parent[i] < i){
      cout << parent[i] << " " << i << " " << weight[i] << endl;
    }else{
      cout << i << " " << parent[i] << " " << weight[i] << endl;
    }
  }

  delete [] visited;
  delete [] parent;
  delete [] weight;
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
    for(int i = 0; i < n; i++){
      cin >> f >> s >> w;
      edges[f][s] = w;
      edges[s][f] = w;
    }

    primAlgo(edges,n);

    for(int i = 0; i < n; i++){
      delete [] edges[i];
    }
    delete [] edges;
  }
  return 0;
}
