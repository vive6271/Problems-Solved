#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, e;
    cin >> n >> e;
    int **edges = new int*[n+1];
    for(int i = 0; i <= n; i++){
      edges[i] = new int[n+1];
      for(int j = 0; j <= n; j++){
        if(i == j){
          edges[i][j] = 0;
        }else{
          edges[i][j] = INT_MAX;
        }
      }
    }
    int f, s, w;
    for(int i = 0; i < e; i++){
      cin >> f >> s >> w;
      edges[f][s] = edges[s][f] = min(edges[f][s],w);// Note :- use min function always
    }

    for(int k = 1; k <= n; k++){
      for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
          if(edges[i][k] != INT_MAX && edges[k][j] != INT_MAX && (edges[i][j] > edges[i][k] + edges[k][j])){
            edges[i][j] = edges[i][k] + edges[k][j];
          }
        }
      }
    }

    int q;
    cin >> q;
    while(q--){
      cin >> f >> s;
      cout << edges[f][s] << endl;
    }

    for(int i = 0; i <= n; i++){
      delete [] edges[i];
    }
    delete [] edges;
  }
  return 0;
}
