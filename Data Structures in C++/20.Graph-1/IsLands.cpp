/*
Q. Islands

An island is a small piece of land surrounded by water . A group of islands is said to be connected 
if we can reach from any given island to any other island in the same group . 
Given V islands (numbered from 0 to V-1) and E connections or edges between islands. 
Can you count the number of connected groups of islands.


Sample Input 1:
5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3

Sample Output 1:
1 

*/

#include<iostream>
using namespace std;

void checkConnectedDFS(int **edges, int n, int sv, bool *visited){
  visited[sv] = true;
  for(int i = 0; i < n; i++){
    if(i != sv && edges[sv][i] == 1 && !visited[i]){
      checkConnectedDFS(edges, n, i, visited);
    }
  }
}

int isLands(int **edges, int n){
  int count = 0;
  bool *visited = new bool[n];
  for(int i = 0; i < n; i++){
    visited[i] = false;
  }
  for(int i = 0; i < n; i++){
    if(!visited[i]){
      checkConnectedDFS(edges, n, i, visited);
      count++;
    }
  }
  return count;
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
  cout << isLands(edges, n) << endl;
  for(int i = 0; i < n; i++){
    delete [] edges[i];
  }
  delete [] edges;
  return 0;
}
