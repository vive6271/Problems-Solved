#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

bool bipartite(vector<int>* edges, int n){
  if(n == 0){
    return true;
  }
  unordered_set<int> sets[2];
  vector<int> pending;

  sets[0].insert(0);
  pending.push_back(0);
  while(pending.size() > 0){
    int current = pending.back();
    pending.pop_back();
    int currentSet = sets[0].count(current) > 0 ? 0 : 1;
    for(int i = 0; i < edges[current].size(); i++){
      int neighbor = edges[current][i];
      if(sets[0].count(neighbor) == 0 && sets[1].count(neighbor) == 0){
        sets[1 - currentSet].insert(neighbor);
        pending.push_back(neighbor);
      }else if(sets[currentSet].count(neighbor) > 0){
        return false;
      }
    }
  }
  return true;
}

int findParent(int *parent, int x){
  if(parent[x] == x){
    return x;
  }
  return findParent(parent, parent[x]);
}

void makeUnion(int* parent, int* rank, int x, int y){
  int px = findParent(parent, x);
  int py = findParent(parent, y);
  if(px == py){
    return;
  }else if(rank[px] < rank[py]){
    parent[px] = py;
  }else if(rank[px] > rank[py]){
    parent[py] = px;
  }else{
    parent[py] = px;
    rank[px]++;
  }
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
      int n, q, x, y, val;
      cin >> n >> q;
      vector<int>* edges = new vector<int>[n];
      int parent[n];
      int rank[n] = {0};
      for(int i = 0; i < n; i++){
        parent[i] = i;
      }
      bool isValid = true;
      for(int i = 0; i < q; i++){
        cin >> x >> y >> val;
        x--;
        y--;
        if(x == y && val == 1){
          isValid = false;
        }
        if(val == 0){
          makeUnion(parent, rank, x, y);
        }else{
          edges[x].push_back(y);
          edges[y].push_back(x);
        }
      }
      if(!isValid){
        cout << "no" << endl;
        delete [] edges;
        continue;
      }
      vector<int>* nedges=new vector<int>[n];
      for(int i = 0; i < n; i++){
        for(int j = 0; j < edges[i].size(); j++){
          int curr = edges[i][j];
          int p1 = findParent(parent, i);
          int p2 = findParent(parent, curr);
          if(p1 == p2){
            isValid = false;
            break;
          }else{
            nedges[p1].push_back(p2);
            nedges[p2].push_back(p1);
          }
        }
        if(!isValid){
          break;
        }
      }
      if(!isValid){
        cout << "no" << endl;
        delete [] edges;
        delete [] nedges;
        continue;
      }
      if(bipartite(nedges, n)){
        cout << "yes" << endl;
      }else{
        cout << "no" << endl;
      }
      delete [] edges;
      delete [] nedges;
    }
    return 0;
}
