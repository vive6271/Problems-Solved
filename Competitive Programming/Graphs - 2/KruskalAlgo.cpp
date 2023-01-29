#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

class Edges{
public:
  int source;
  int destination;
  int weight;
};

bool compare(Edges e1, Edges e2){
  return (e1.weight < e2.weight);
}

int findParent(int *parent, int v){
  if(parent[v] == v){
    return v;
  }
  return parent[v] = findParent(parent, parent[v]);
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, e;
    cin >> n >> e;

    Edges *input = new Edges[e];
    for(int i = 0; i < e; i++){
      cin >> input[i].source >> input[i].destination >> input[i].weight;
    }

    sort(input, input+e, compare);
    int *parent = new int[n];
    for(int i = 0; i < n; i++){
      parent[i] = i;
    }

    Edges *output = new Edges[n-1];
    int i = 0, j = 0;
    while(j < n-1){
      Edges currentEdge = input[i];
      int v1 = findParent(parent, currentEdge.source);
      int v2 = findParent(parent, currentEdge.destination);
      if(v1 != v2){
        output[j++] = currentEdge;
        parent[v2] = v1;
      }
      i++;
    }

    int count = 0;
    for(int i = 0; i < n-1; i++){
      count += output[i].weight;
    }
    cout << count << endl;
    delete [] parent;
    delete [] input;
    delete [] output;
  }
  return 0;
}
