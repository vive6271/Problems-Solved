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
  return ((x >= 0 && x < n) && (y >= 0 && y < m));
}

void dfs(vector<int>* edges, int start, int &num, bool *visited){
  visited[start] = true;
  num++;
  for(int i = 0; i < edges[start].size(); i++){
    int next = edges[start][i];
    if(!visited[next]){
      dfs(edges, next, num, visited);
    }
  }
}

int connectedHorses(vector<int>* edges, int n){
  bool *visited = new bool[n]();
  int ans = 1;
  for(int i = 0; i < n; i++){
    if(!visited[i]){
      int num = 0;
      dfs(edges, i, num, visited);
      ans = (ans * fact[num]) % MOD;
    }
  }
  delete [] visited;
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
    int board[n][m];
    memset(board, -1, sizeof(board));
    for(int i = 0; i < q; i++){
      int x, y;
      cin >> x >> y;
      board[x-1][y-1] = i;
    }

    vector<int> *edges = new vector<int>[q];
    int moves[8][2] = {{-2,-1},{-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}};
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(board[i][j] != -1){
          for(int k = 0; k < 8; k++){
            int x = i + moves[k][0];
            int y = j + moves[k][1];
            if(isValid(n, m, x, y) && board[x][y] != -1){
              int a = board[i][j], b = board[x][y];
              edges[a].push_back(b);
              edges[b].push_back(a);
            }
          }
        }
      }
    }

    cout << connectedHorses(edges, q) << endl;
    delete [] edges;
  }
}
