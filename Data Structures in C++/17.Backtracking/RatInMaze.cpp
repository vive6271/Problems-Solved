/*
Q. Rat In A Maze Problem

You are given an integer N and a binary 2D array of size N*N. The given binary matrix represents a maze and 
a rat starts from the top left cell and has to reach to the bottom right cell of the maze. 
The rat can move in all the four directions: up, down, left and right.

In the given binary matrix, 0 signifies the cell is a dead end and 1 signifies the cell can be used to move from source to destination cell.

You have to print all the paths, following which rat can move from the top left cell to the bottom right cell of the given binary matrix.

Sample Input 1 :
3
1 0 1
1 0 1
1 1 1

Sample Output 1 :
1 0 0 1 0 0 1 1 1 

Explanation :
Only 1 path is possible. The path is shown in the image below.

Sample Input 2 :
3
1 0 1
1 1 1
1 1 1

Sample Output 2 :
1 0 0 1 1 1 1 1 1 
1 0 0 1 0 0 1 1 1 
1 0 0 1 1 0 0 1 1 
1 0 0 1 1 1 0 0 1 

Explanation:
As described in the Sample Output 2, four paths are possible.

*/

#include <bits/stdc++.h>
using namespace std;

int maze[20][20], mazeHelp[20][20];

bool isPossible(int n, int row, int col){
  return (row >= 0 && row < n) && (col >= 0 && col < n) && (maze[row][col] == 1) && (mazeHelp[row][col] == 0);
}

void ratInMazeHelper(int n, int row, int col){
  if(row == n-1 && col == n-1){
    mazeHelp[row][col] = 1;
    for(int i = 0; i < n; i++){
      for(int  j = 0; j < n; j++){
        cout << mazeHelp[i][j] << " ";
      }
    }
    cout << endl;
    //mazeHelp[row][col] = 0; Optional
    return;
  }
  if(!isPossible(n,row,col)){
    return;
  }
  mazeHelp[row][col] = 1;
  ratInMazeHelper(n,row-1,col);
  ratInMazeHelper(n,row,col+1);
  ratInMazeHelper(n,row+1,col);
  ratInMazeHelper(n,row,col-1);
  mazeHelp[row][col] = 0;
}

void ratInMaze(int n){
  memset(mazeHelp, 0, 20*20*sizeof(int));
  ratInMazeHelper(n, 0, 0);
}

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> maze[i][j];
    }
  }
  ratInMaze(n);
  return 0;
}
