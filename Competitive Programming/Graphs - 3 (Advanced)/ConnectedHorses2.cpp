#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long int
#define endl '\n'
int fact[100001];

void factorial(){
  fact[0] = 1;
  for(int i = 1; i < 100001; i++){
    fact[i] = (fact[i-1] * i) % MOD;
  }
}

bool isValid(int n, int m, int x, int y){
  return ((x >= 1 && x <= n) && (y >= 1 && y <= m));
}

int dfs(bool** edges, int x, int y, int n, int m){
  int count = 1;
  edges[x][y] = false;
  int moves[8][2] = {{-2,-1},{-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}};
  for(int i = 0; i < 8; i++){
    int a = x + moves[i][0];
    int b = y + moves[i][1];
    if(isValid(n, m, a, b) && edges[a][b]){
      count += dfs(edges, a, b, n, m);
    }
  }
  return count;
}

int connectedHorses(bool** edges, int n, int m){
  int ans = 1, count;
  for(int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      if(edges[i][j]){
        count = dfs(edges, i, j, n, m);
        ans = (ans * fact[count]) % MOD;
      }
    }
  }
  return ans;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  factorial();
  while(t--){
    int n, m, q;
    cin >> n >> m >> q;
    bool **edges = new bool*[n+1];
    for(int i = 0; i <= n; i++){
      edges[i] = new bool[m+1];
      for(int j = 0; j <= m; j++){
        edges[i][j] = false;
      }
    }

    for(int i = 0; i < q; i++){
      int a, b;
      cin >> a >> b;
      edges[a][b] = true;
    }
    cout << connectedHorses(edges, n, m) << endl;
    for(int i = 0; i <= n; i++){
      delete [] edges[i];
    }
    delete [] edges;
  }
}
