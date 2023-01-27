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

void mazeHelper(int maze[][20], int n, int **mazeHelp, int row, int col){
  if(row == n-1 && col == n-1){
    mazeHelp[row][col] = 1;
    for(int i = 0; i < n; i++){
      for(int  j = 0; j < n; j++){
        cout << mazeHelp[i][j] << " ";
      }
    }
    cout << endl;
    mazeHelp[row][col] = 0;
    return;
  }
  if(row >= n || row < 0 || col >= n || col < 0 || maze[row][col] == 0 || mazeHelp[row][col] == 1){
    return;
  }
  mazeHelp[row][col] = 1;
  mazeHelper(maze, n, mazeHelp, row-1, col);
  mazeHelper(maze, n, mazeHelp, row+1, col);
  mazeHelper(maze, n, mazeHelp, row, col-1);
  mazeHelper(maze, n, mazeHelp, row, col+1);
  mazeHelp[row][col] = 0;
}

void ratInMaze(int maze[][20], int n){
  int **mazeHelp = new int*[n];
  for(int i = 0; i < n; i++){
    mazeHelp[i] = new int[n];
    memset(mazeHelp[i], 0, n*sizeof(int));
  }
  mazeHelper(maze, n, mazeHelp, 0, 0);
}

int main(){
  int n, maze[20][20];
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> maze[i][j];
    }
  }
  ratInMaze(maze, n);
  return 0;
}
