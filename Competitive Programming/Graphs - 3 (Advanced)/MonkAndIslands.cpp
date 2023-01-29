#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

int countIslands(vector<int>* edges, int n){
  bool *visited = new bool[n]();
  int *count = new int[n];
  queue<int> q;
  q.push(0);
  count[0] = 0;
  visited[0] = true;
  while(!q.empty()){
    int front = q.front();
    q.pop();
    for(int i = 0; i < edges[front].size(); i++){
      int next = edges[front][i];
      if(!visited[next]){
        q.push(next);
        visited[next] = true;
        count[next] = count[front]+1;
        if(next == n-1){
          break;
        }
      }
    }
  }
  int ans = count[n-1];
  delete [] visited;
  delete [] count;
  return ans;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, q;
    cin >> n >> q;
    vector<int>* edges = new vector<int>[n];
    for(int i = 0; i < q; i++){
      int x, y;
      cin >> x >> y;
      edges[x-1].push_back(y-1);
      edges[y-1].push_back(x-1);
    }
    cout << countIslands(edges, n) << endl;
    delete [] edges;
  }
  return 0;
}
