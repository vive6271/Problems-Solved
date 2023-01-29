#include<bits/stdc++.h>
using namespace std;

vector<int> *bfsPath(int **edges, int n, int v1, int v2, bool *visited){
  unordered_map<int,int> Map;
  queue<int> q;
  vector<int> *v = new vector<int>();
  bool isDone = false;
  q.push(v1);
  visited[v1] = true;
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

  if(!isDone){
    delete v;
    return NULL;
  }

  int key = v2;
  v -> push_back(key);
  while(key != v1){
    v -> push_back(Map[key]);
    key = Map[key];
  }
  return v;
}

void getPath(int **edges, int n, int v1, int v2){
  bool *visited = new bool[n];
  for(int i = 0; i < n; i++){
    visited[i] = false;
  }
  vector<int> *v = bfsPath(edges, n, v1, v2, visited);
  delete [] visited;
  if(v == NULL){
    return;
  }else{
    for(int i = 0; i < v -> size(); i++){
      cout << v -> at(i) << " ";
    }
    cout << endl;
    delete v;
  }
}

int main(){
  int t;
  cin >> t;
  while(t--){
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
  }
  return 0;
}
