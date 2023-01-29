#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

int foundCycle(vector<int> *u, vector<int> *v, int n, int m){
  int **edges = new int*[n];
  for(int i = 0; i < n; i++){
    edges[i] = new int[n];
    for(int j = 0; j < n; j++){
      edges[i][j] = 0;
    }
  }

  int f, s, count = 0;
  for(int i = 0; i < m; i++){
    f = u -> at(i) - 1;
    s = v -> at(i) - 1;
    edges[f][s] = 1;
    edges[s][f] = 1;
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(edges[i][j] == 1 && i != j){
        for(int k = 0; k < n; k++){
          if(edges[j][k] == 1 && edges[i][k] == 1 && i != k && j != k){
            count++;
          }
        }
      }
    }
  }
  for(int i = 0; i < n; i++){
    delete [] edges[i];
  }
  delete [] edges;
  return count/6;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m, x;
  cin >> n >> m;
  vector<int> *u = new vector<int>();
  vector<int> *v = new vector<int>();
  for(int i = 0; i < m; i++){
    cin >> x;
    u -> push_back(x);
  }

  for(int i = 0; i < m; i++){
    cin >> x;
    v -> push_back(x);
  }
  cout << foundCycle(u, v, n, m) << endl;
  delete u;
  delete v;
  return 0;
}
