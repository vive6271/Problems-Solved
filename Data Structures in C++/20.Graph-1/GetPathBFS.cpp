/*
Q. Get Path - BFS

Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), 
find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.

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
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

vector<int> *pathBFS(int **edges, int n, int sv, int v2, bool *visited){
  unordered_map<int,int> Map;
  vector<int> *v = new vector<int>();
  queue<int> q;
  q.push(sv);
  visited[sv] = true;
  bool isDone = false;
  while(!q.empty() && !isDone){
    int front = q.front();
    q.pop();
    for(int i = 0; i < n; i++){
      if(i != front && edges[front][i] == 1 && !visited[i]){
        q.push(i);
        visited[i] = true;
        Map[i] = front;
        if(i == v2){
          isDone = true;
          break;
        }
      }
    }
  }
  if(!visited[v2]){
    delete v;
    return NULL;
  }

  int key = v2;
  v -> push_back(key);
  while(key != sv){
    v -> push_back(Map[key]);
    key = Map[key];
  }
  return v;
}


void getPath(int **edges, int n, int sv, int v2){
  bool *visited = new bool[n];
  for(int i = 0; i < n; i++){
    visited[i] = false;
  }
  vector<int> *v = pathBFS(edges, n, sv, v2, visited);
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
