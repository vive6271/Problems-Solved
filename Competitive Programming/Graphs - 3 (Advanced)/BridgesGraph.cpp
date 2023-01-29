#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

void dfs(vector<int> *edges, int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer){
  vis[node] = true;
  tin[node] = low[node] = timer++;
  for(auto it: edges[node]){
    if(it == parent){
      continue;
    }

    if(!vis[it]){
      dfs(edges, it, node, vis, tin, low, timer);
      low[node] = min(low[node], low[it]);

      if(low[it] > tin[node]){
        cout << node << " " << it << endl;
      }
    }else{
      low[node] = min(low[node], tin[it]);
    }
  }
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m, x, y;
  cin >> n >> m;
  vector<int> edges[n+1];
  for(int i = 0; i < m; i++){
    cin >> x >> y;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }

  vector<int> tin(n, -1);
	vector<int> low(n, -1);
	vector<int> vis(n, 0);
	int timer = 0;
	for(int i = 0; i < n; i++) {
	    if(!vis[i]) {
	        dfs(edges, i, -1, vis, tin, low, timer);
	    }
	}
  return 0;
}
