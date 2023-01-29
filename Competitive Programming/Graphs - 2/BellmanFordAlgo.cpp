#include<bits/stdc++.h>
using namespace std;

class Edges{
public:
  int v1;
  int v2;
  int weight;
};

void bellmanFord(int n, int e, Edges** edges){
  int* dist = new int[n];
  for(int i = 0; i < n; i++){
    dist[i] = INT_MAX;
  }
  dist[0] = 0;
  for(int i = 0; i < n-1; i++){
    for(int j = 0; j < e; j++){
      int u = edges[j] -> v1;
      int v = edges[j] -> v2;
      int w = edges[j] -> weight;
      if(dist[u] != INT_MAX && (dist[v] > dist[u] + w)){
        dist[v] = dist[u] + w;
      }
    }
  }
  //Cycle Detection
  bool isCycle = false;
  for(int i = 0; i < e; i++){
    int u = edges[i] -> v1;
    int v = edges[i] -> v2;
    int w = edges[i] -> weight;
    if(dist[u] != INT_MAX && (dist[v] > dist[u] + w)){
      isCycle = true;
      break;
    }
  }
  if(isCycle){
    cout << "Cycle Found" << endl;
    return;
  }
  for(int i = 0; i < n; i++){
    cout << dist[i] << endl;
  }
  delete [] dist;
}

int main(){
  int n, e;
  cin >> n >> e;

  Edges** edges = new Edges*[e];
  for(int i = 0; i < e; i++){
    edges[i] = new Edges();
    cin >> edges[i] -> v1 >> edges[i] -> v2 >> edges[i] -> weight;
  }
  bellmanFord(n, e, edges);
  for(int i = 0; i < e; i++){
    delete [] edges[i];
  }
  delete [] edges;
  return 0;
}
