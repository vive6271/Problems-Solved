#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

class Edge{
public:
  int source;
  int destination;
  int weight;
  int index;
};

bool compare(Edge &e1, Edge &e2){
  return (e1.weight < e2.weight);
}

int findParent(int* parent, int x){
  if(parent[x] == x){
    return x;
  }
  return parent[x] = findParent(parent, parent[x]);
}

void dfs(vector<pair<int,int>> *edges, int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, int* ans){
  vis[node] = true;
  tin[node] = low[node] = timer++;
  for(int i = 0; i < edges[node].size(); i++){

    int fVal = edges[node][i].first;
    int sVal = edges[node][i].second;

    if(fVal == parent){
      continue;
    }

    if(!vis[fVal]){
      dfs(edges, fVal, node, vis, tin, low, timer, ans);
      low[node] = min(low[node], low[fVal]);

      if(low[fVal] > tin[node]){
        ans[sVal] = 1;
      }
    }else{
      low[node] = min(low[node], tin[fVal]);
    }
  }
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, e, a, b, w;
  cin >> n >> e;
  Edge* input = new Edge[e];
  vector<pair<int,int>> edges[n+1];
  int* ans = new int[e];
  for(int i = 0; i < e; i++){
    cin >> a >> b >> w;
    input[i].source = a;
    input[i].destination = b;
    input[i].weight = w;
    input[i].index = i;
    
    edges[a].push_back({b,i});
    edges[b].push_back({a,i});
    ans[i] = 0; // At least
  }

  sort(input, input+e, compare);
  int* parent = new int[n+1];
  for(int i = 0; i <= n; i++){
    parent[i] = i;
  }

  int i = 0, j = 0;
  while(i < e){
    if(j < n-1){
      if(i+1 < e && input[i].weight == input[i+1].weight){
        int wt = input[i].weight, k = i, dCount = 0;
        int isCycle = 0;
        while(k < e && wt == input[k].weight){
          int p1 = findParent(parent, input[k].source);
          int p2 = findParent(parent, input[k].destination);
          if(p1 != p2){
            parent[p2] = p1;
          }else{
            isCycle++;
          }
          k++;
          dCount++;
        }
        if(isCycle == 0 && (i+dCount-1) < n-1){
          while(dCount--){
            int idx = input[i].index;
            ans[idx] = 1;
            j++;
          }
        }else{
          j++;
        }
        i += dCount-1;
      }else{
        int p1 = findParent(parent, input[i].source);
        int p2 = findParent(parent, input[i].destination);
        int idx = input[i].index;
        if(p1 != p2){
          parent[p2] = p1;
          ans[idx] = 1;
          j++;
        }else{
          ans[idx] = -1;
        }
      }
      i++;
    }else{
      int idx = input[i].index;
      ans[idx] = -1;
      i++;
    }
  }
  //Bridge
  vector<int> tin(n, -1);
  vector<int> low(n, -1);
  vector<int> vis(n, 0);
  int timer = 0;
  for(int i = 0; i < n; i++) {
      if(!vis[i]) {
          dfs(edges, i, -1, vis, tin, low, timer, ans);
      }
  }

  for(int i = 0; i < e; i++){
    if(ans[i] == 0){
      cout << "at least one" << endl;
    }else if(ans[i] == 1){
      cout << "any" << endl;
    }else{
      cout << "none" << endl;
    }
  }
  return 0;
}
