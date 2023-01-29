#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

class Edge{
public:
  int source;
  int destination;
  int weight;
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

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, e, cost;
    cin >> n >> e >> cost;
    Edge* input = new Edge[e];
    for(int i = 0; i < e; i++){
      cin >> input[i].source >> input[i].destination >> input[i].weight;
    }
    sort(input, input+e, compare);
    int* parent = new int[n+1];
    for(int i = 0; i <= n; i++){
      parent[i] = i;
    }
    int i = 0, j = 0, roadCost = 0, airportCost = 0;
    while(j < n-1 && i < e){
      int p1 = findParent(parent, input[i].source);
      int p2 = findParent(parent, input[i].destination);
      if(p1 != p2 && input[i].weight < cost){
        parent[p2] = p1;
        roadCost += input[i].weight;
        j++;
      }
      i++;
    }
    for(int i = 1; i <= n; i++){
      if(parent[i] == i){
        airportCost += cost;
      }
    }
    cout << roadCost+airportCost << endl;
    delete [] input;
    delete [] parent;
  }
  return 0;
}
