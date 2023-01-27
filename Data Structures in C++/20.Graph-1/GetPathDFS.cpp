/*
Q. Get Path - DFS

Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), 
find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.

Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.

Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3

Sample Output 1 :
3 0 1

Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
(No Output)
*/

#include<iostream>
using namespace std;
#include<vector>

vector<int> *pathDFS(int **edges, int n, int sv, int v2, bool *visited){
  visited[sv] = true;
  if(sv == v2){
    vector<int> *v = new vector<int>();
    v -> push_back(sv);
    return v;
  }
  for(int i = 0; i < n; i++){
    if(i != sv && edges[sv][i] == 1 && !visited[i]){
      vector<int> *v = pathDFS(edges, n, i, v2, visited);
      if(v != NULL){
        v -> push_back(sv);
        return v;
      }
    }
  }
  return NULL;
}

void getPath(int **edges, int n, int sv, int v2){
  bool *visited = new bool[n];
  for(int i = 0; i < n; i++){
    visited[i] = false;
  }
  vector<int> *v = pathDFS(edges, n, sv, v2, visited);
  if(v == NULL){
    return;
  }
  for(int i = 0; i < v -> size(); i++){
    cout << v -> at(i) << " ";
  }
  cout << endl;
  delete [] visited;
  delete v;
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
  getPath(edges, n, v1, v2);
  for(int i = 0; i < n; i++){
    delete [] edges[i];
  }
  delete [] edges;
  return 0;
}
