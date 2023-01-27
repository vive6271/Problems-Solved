/*
Q. Has Path

Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), 
check if there exists any path between them or not. Print true if the path exists and false otherwise.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.

Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3

Sample Output 1 :
true

Sample Input 2 :
6 3
5 3
0 1
3 4
0 3

Sample Output 2 :
false
*/

#include<iostream>
using namespace std;
/*
void checkDFS(int **edges, int n, int sv, bool *visited){
  visited[sv] = true;
  for(int i = 0; i < n; i++){
    if(i == sv){
      continue;
    }
    if(edges[sv][i] == 1 && !visited[i]){
      checkDFS(edges, n, i, visited);
    }
  }
}

void setFalse(bool *visited, int n){
  for(int i = 0; i < n; i++){
    visited[i] = false;
  }
}

bool hasPath(int **edges, int n, int v1, int v2){
  bool *visited = new bool[n];
  setFalse(visited,n);
  for(int i = 0; i < n; i++){
    if(!visited[i]){
      checkDFS(edges, n, i, visited);
      if(visited[v1] && visited[v2]){
        return true;
      }
      setFalse(visited,n);
    }
  }
  delete [] visited;
  return false;
}
*/
void hasPathHelper(int **edges, int n, int sv, int v2, bool *visited){
  visited[sv] = true;
  if(visited[v2] == true){
    return;
  }
  for(int i = 0; i < n; i++){
    if(i == sv){
      continue;
    }
    if(edges[sv][i] == 1 && !visited[i]){
      hasPathHelper(edges, n, i, v2, visited);
    }
  }
}

bool hasPath(int **edges, int n, int sv, int v2){
  bool *visited = new bool[n];
  for(int i = 0; i < n; i++){
    visited[i] = false;
  }
  hasPathHelper(edges, n, sv, v2, visited);
  bool ans = visited[v2];
  delete [] visited;
  return ans;
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
  int v1, v2;
  cin >> v1 >> v2;

  cout << (hasPath(edges, n, v1, v2) ? "true" : "false") << endl;

  for(int i = 0; i < n; i++){
    delete [] edges[i];
  }
  delete [] edges;
  return 0;
}
