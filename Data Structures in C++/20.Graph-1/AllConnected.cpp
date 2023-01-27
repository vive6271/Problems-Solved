/*
Q. All connected components

Given an undirected graph G(V,E), find and print all the connected components of the given graph G.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. 
   And then print them in the main, not inside function.

Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.

Sample Input 1:
4 2
0 1
2 3

Sample Output 1:
0 1 
2 3 

Sample Input 2:
4 3
0 1
1 3 
0 3

Sample Output 2:
0 1 3 
2


*/

#include<bits/stdc++.h>
using namespace std;

/*
vector<int> *BFSComponent(int **edges, int n, int sv, bool *visited){
  vector<int> *v = new vector<int>();
  queue<int> q;
  q.push(sv);
  visited[sv] = true;
  while(!q.empty()){
    int front = q.front();
    q.pop();
    v -> push_back(front);
    for(int i = 0; i < n; i++){
      if(i != front && edges[front][i] == 1 && !visited[i]){
        q.push(i);
        visited[i] = true;
      }
    }
  }
  return v;
}

*/

void DFSComponent(int **edges, int n, int sv, bool *visited, vector<int> *v){
  v -> push_back(sv);
  visited[sv] = true;
  for(int i = 0; i < n; i++){
    if(i != sv && edges[sv][i] == 1 && !visited[i]){
      DFSComponent(edges, n, i, visited, v);
    }
  }
}

void connectedGraph(int **edges, int n){
  bool *visited = new bool[n];
  for(int i = 0; i < n; i++){
    visited[i] = false;
  }
  for(int i = 0; i < n; i++){
    if(!visited[i]){
      //vector<int> *v = BFSComponent(edges, n, i, visited); for BFS
      vector<int> *v = new vector<int>();
      DFSComponent(edges, n, i, visited, v);
      sort(v -> begin(), v -> end());
      for(int i = 0; i < v -> size(); i++){
        cout << v -> at(i) << " ";
      }
      cout << endl;
      delete v;
    }
  }
}

int main(){
  int n, e;
  cin >> n >> e;
  int **edges = new int*[n];
  for(int i = 0; i < n; i++){
    edges[i] = new int[n];
    for(int j = 0; j < n; j++){
      edges[i][j] = 0;
    }
  }

  for(int i = 0; i < e; i++){
    int f, s;
    cin >> f >> s;
    edges[f][s] = 1;
    edges[s][f] = 1;
  }
  connectedGraph(edges, n);

  for(int i = 0; i < n; i++){
    delete [] edges[i];
  }
  delete [] edges;
  return 0;
}
