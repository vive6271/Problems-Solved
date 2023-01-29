#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define int long long int
#define endl '\n'

class Edges{
public:
  int v1;
  int v2;
  int weight;
};

void bellmanFord(int n, int e, int a, int b, Edges** edges){
  int* dist = new int[n+1];
  for(int i = 0; i <= n; i++){
    dist[i] = INF;
  }
  dist[a] = 0;
  for(int i = 0; i < n-1; i++){
    for(int j = 0; j < e; j++){
      int u = edges[j] -> v1;
      int v = edges[j] -> v2;
      int w = edges[j] -> weight;
      if(dist[u] != INF && (dist[v] > dist[u] + w)){
        dist[v] = dist[u] + w;
      }
    }
  }
  cout << dist[b] << endl;
  delete [] dist;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, e, a, b;
    cin >> n >> e >> a >> b;

    Edges** edges = new Edges*[e];
    for(int i = 0; i < e; i++){
      edges[i] = new Edges();
      cin >> edges[i] -> v1 >> edges[i] -> v2 >> edges[i] -> weight;
    }
    bellmanFord(n, e, a, b, edges);
    for(int i = 0; i < e; i++){
      delete [] edges[i];
    }
    delete [] edges;
  }
  return 0;
}
