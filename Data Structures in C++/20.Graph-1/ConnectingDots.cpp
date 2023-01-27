/*
Q. Connecting Dots

Gary has a board of size NxM. Each cell in the board is a coloured dot. 
There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). 
Now Gary is getting bored and wants to play a game. The key of this 
game is to find a cycle that contain dots of same colour. 

Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:

1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.

Sample Input 1:
3 4
AAAA
ABCA
AAAA

Sample Output 1:
true


*/


#include <iostream>
#include <vector>
using namespace std;

bool isValid(int n, int m, int x, int y){
  return (x >= 0 && x < n && y >= 0 && y < m);
}

bool checkCycle(vector<vector<char>> &board, int n, int m, int x, int y, bool **visited, char ch){
  bool isCycleFound = false;
  visited[x][y] = true;
  int count = 0;
  while(true){
    if(isValid(n, m, x-1, y) && board[x-1][y] == ch && !visited[x-1][y]){  //Up
      visited[x-1][y] = true;
      x -= 1;
    }else if(isValid(n, m, x+1, y) && board[x+1][y] == ch && !visited[x+1][y]){ //Down
      visited[x+1][y] = true;
      x += 1;
    }else if(isValid(n, m, x, y-1) && board[x][y-1] == ch && !visited[x][y-1]){ //Left
      visited[x][y-1] = true;
      y -= 1;
    }else if(isValid(n, m, x, y+1) && board[x][y+1] == ch && !visited[x][y+1]){ //Right
      visited[x][y+1] = true;
      y += 1;
    }else{
      if(count >= 4 && visited[x][y]){
        isCycleFound = true;
      }
      break;
    }
    count++;
  }
  return isCycleFound;
}

bool hasCycle(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    bool **visited = new bool*[n];
    for(int i = 0; i < n; i++){
      visited[i] = new bool[m];
      for(int j = 0; j < m; j++){
        visited[i][j] = false;
      }
    }
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(!visited[i][j]){
          bool output = checkCycle(board, n, m, i, j, visited, board[i][j]);
          if(output){
            for(int i = 0; i < n; i++){
              delete [] visited[i];
            }
            delete [] visited;
            return true;
          }
        }
      }
    }
    for(int i = 0; i < n; i++){
      delete [] visited[i];
    }
    delete [] visited;
    return false;
}

/* Better
bool hasSameCycle(vector<vector<char>> &board, int i, int j, int iStart, int jStart, int countChar, int n, int m, char ch, vector<vector<bool>> &visited){
    if(visited[i][j]){
        if((iStart == 1 && jStart == j) && countChar >= 4){
            return true;
        }
        return false;
    }
    visited[i][j] = true;
    int arr[][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    for(int k = 0; k < 4; k++){
        int a = i + arr[k][0], b = j + arr[k][1];
        if((a >= 0 && a < n) && (b >= 0 && b < m) && board[a][b] == ch){
            if(hasSameCycle(board, a, b, iStart, jStart, countChar+1, n, m, ch, visited)){
                return true;
            }
        }
    }
    visited[i][j] = false;
    return false;
}

bool hasCycle(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j]){
                if(hasSameCycle(board, i, j, i, j, 0, n, m, board[i][j], visited)){
                    return true;
                }
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
    cout << (hasCycle(board, n, m) ? "true" : "false");
}
