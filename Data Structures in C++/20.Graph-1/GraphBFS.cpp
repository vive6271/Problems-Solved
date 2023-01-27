/*
Q. BFS Traversal

Given an undirected and disconnected graph G(V, E), print its BFS traversal.

Note:
1. Here you need to consider that you need to print BFS path starting from vertex 0 only. 
2. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
3. E is the number of edges present in graph G.
4. Take graph input in the adjacency matrix.
5. Handle for Disconnected Graphs as well

Sample Input 1:
4 4
0 1
0 3
1 2
2 3

Sample Output 1:
0 1 3 2

*/

#include<iostream>
#include<queue>
using namespace std;

void printBFS(int **edges, int n, int sv, bool *visited){
  queue<int> q;
  q.push(sv);
  visited[sv] = true;
  while(!q.empty()){
    int front = q.front();
    q.pop();
    cout << front << " ";
    for(int i = 0; i < n; i++){
      if(i ==  front){
        continue;
      }
      if(edges[front][i] == 1 && !visited[i]){
        q.push(i);
        visited[i] = true;
      }
    }
  }
}

void disconnectedGraph(int **edges, int n, bool *visited){
  for(int i = 0; i < n; i++){
    if(!visited[i]){
      printBFS(edges, n, i, visited);
    }
  }
  cout << endl;
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

  bool *visited = new bool[n];
  for(int i = 0; i < n; i++){
    visited[i] = false;
  }
  disconnectedGraph(edges, n, visited);

  for(int i = 0; i < n; i++){
    delete [] edges[i];
  }
  delete [] edges;
  delete [] visited;
  return 0;
}
