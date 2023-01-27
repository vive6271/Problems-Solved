/*
Q. Coding Ninjas

Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.

Sample Input 1:
2 11
CXDXNXNXNXA
XOXIXGXIXJX

Sample Output 1:
1

*/

#include <iostream>
#include <vector>
using namespace std;

bool isValid(int n, int m, int x, int y){
  return (x >= 0 && x < n && y >= 0 && y < m);
}

bool hasPathHelper(vector<vector<char>> &board, int n, int m, int x, int y, string str, bool **visited){
  if(str.size() == 0){
    return true;
  }
  visited[x][y] = true;
  //Up Left
  if(isValid(n, m, x-1, y-1) && board[x-1][y-1] == str[0] && !visited[x-1][y-1]){
    if(hasPathHelper(board, n, m, x-1, y-1, str.substr(1), visited)){
      return true;
    }
  }
  //Left
  if(isValid(n, m, x, y-1) && board[x][y-1] == str[0] && !visited[x][y-1]){
    if(hasPathHelper(board, n, m, x, y-1, str.substr(1), visited)){
      return true;
    }
  }
  //Down Left
  if(isValid(n, m, x+1, y-1) && board[x+1][y-1] == str[0] && !visited[x+1][y-1]){
    if(hasPathHelper(board, n, m, x+1, y-1, str.substr(1), visited)){
      return true;
    }
  }

  //Up
  if(isValid(n, m, x-1, y) && board[x-1][y] == str[0] && !visited[x-1][y]){
    if(hasPathHelper(board, n, m, x-1, y, str.substr(1), visited)){
      return true;
    }
  }
  //Down
  if(isValid(n, m, x+1, y) && board[x+1][y] == str[0] && !visited[x+1][y]){
    if(hasPathHelper(board, n, m, x+1, y, str.substr(1), visited)){
      return true;
    }
  }
  //Up Right
  if(isValid(n, m, x-1, y+1) && board[x-1][y+1] == str[0] && !visited[x-1][y+1]){
    if(hasPathHelper(board, n, m, x-1, y+1, str.substr(1), visited)){
      return true;
    }
  }
  //Right
  if(isValid(n, m, x, y+1) && board[x][y+1] == str[0] && !visited[x][y+1]){
    if(hasPathHelper(board, n, m, x, y+1, str.substr(1), visited)){
      return true;
    }
  }
  //Down Right
  if(isValid(n, m, x+1, y+1) && board[x+1][y+1] == str[0] && !visited[x+1][y+1]){
    if(hasPathHelper(board, n, m, x+1, y+1, str.substr(1), visited)){
      return true;
    }
  }
  visited[x][y] = false;
  return false;
}

bool hasPath(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    string str = "CODINGNINJA";
    bool **visited = new bool*[n];
    for(int i = 0; i < n; i++){
      visited[i] = new bool[m];
      for(int j = 0; j < m; j++){
        visited[i][j] = false;
      }
    }
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(board[i][j] == str[0]){
          if(hasPathHelper(board, n, m, i, j, str.substr(1), visited)){
            return true;
          }
        }
      }
    }
    return false;
}

/* Better
bool isValid(vector<vector<char>> &board, int i, int j, int n, int m, char ch, vector<vector<bool>> &visited){
    return (i >= 0 && i < n) && (j >= 0 && j < m) && (board[i][j] == ch) && !visited[i][j];
}

bool dfsTraversal(vector<vector<char>> &board, int i, int j, int n, int m, string str, vector<vector<bool>> &visited){
    visited[i][j] = true;
    if(str.length() == 0){
        return true;
    }
    int arr[][2] = {{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};
    for(int k = 0; k < 8; k++){
        int a = i + arr[k][0];
        int b = j + arr[k][1];
        if(isValid(board, a, b, n, m, str[0], visited)){
            if(dfsTraversal(board, a, b, n, m, str.substr(1), visited)){
                return true;
            }
        }
    }
    visited[i][j] = false;
    return false;
}

bool hasPath(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    string str = "CODINGNINJA";
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(board[i][j] == str[0]){
            visited[i][j] = true;
            if (dfsTraversal(board, i, j, n, m, str.substr(1), visited)) {
              return true;
            }
            visited[i][j] = false;
        }
      }
    }
    return false;
}
*/

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0);
}
