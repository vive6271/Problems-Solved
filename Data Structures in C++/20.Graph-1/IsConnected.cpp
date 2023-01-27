/*
Q. Is Connected ?

Given an undirected graph G(V,E), check if the graph G is connected graph or not.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.

Sample Input 1:
4 4
0 1
0 3
1 2
2 3

Sample Output 1:
true

Sample Input 2:
4 3
0 1
1 3 
0 3

Sample Output 2:
false 

*/

#include<iostream>
using namespace std;

void checkDFS(int **edges, int n, int sv, bool *visited){
  visited[sv] = true;
  for(int i = 0; i < n; i++){
    if(i != sv && edges[sv][i] == 1 && !visited[i]){
      checkDFS(edges, n, i, visited);
    }
  }
}

bool isConnected(int **edges, int n){
  bool *visited = new bool[n];
  for(int i = 0; i < n; i++){
    visited[i] = false;
  }
  checkDFS(edges, n, 0, visited);
  for(int i = 0; i < n; i++){
    if(!visited[i]){
      delete [] visited;
      return false;
    }
  }
  delete [] visited;
  return true;
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
  cout << (isConnected(edges, n) ? "true" : "false") << endl;
  for(int i = 0; i < n; i++){
    delete [] edges[i];
  }
  delete [] edges;
  return 0;
}
