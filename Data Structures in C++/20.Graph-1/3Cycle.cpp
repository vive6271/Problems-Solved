/*
Q. 3-Cycle

Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, then count the distinct 3-cycles in the graph. 
A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.

Sample Input 1:
3 3
0 1
1 2
2 0

Sample Output 1:
1

*/

#include<iostream>
using namespace std;

int CycleCount(int **edges, int n){
  int count = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(edges[i][j] == 1){
        for(int k = 0; k < n; k++){
          if(edges[j][k] == 1 && edges[i][k] == 1){
            count++;
          }
        }
      }
    }
  }
  return count/6;
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
  cout << CycleCount(edges, n) << endl;

  for(int i = 0; i < n; i++){
    delete [] edges[i];
  }
  delete [] edges;
  return 0;
}
