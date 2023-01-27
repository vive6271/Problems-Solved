/*
Q. Sudoku Solver

Coding Ninjas has provided you a 9*9 sudoku board. The board contains non zero and zero values. 
Non zero values lie in the range: [1, 9]. Cells with zero value indicate that the particular cell 
is empty and can be replaced by non zero values.

You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true, otherwise print false.

Sample Input 1:

9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6

Sample Output 1:
true

*/
#include <bits/stdc++.h>
using namespace std;
#define N 9

bool checkRow(int grid[N][N], int row, int num){
  for(int i = 0; i < N; i++){
    if(grid[row][i] == num){
      return false;
    }
  }
  return true;
}

bool checkCol(int grid[N][N],int col, int num){
  for(int i = 0; i < N; i++){
    if(grid[i][col] == num){
      return false;
    }
  }
  return true;
}

bool checkBox(int grid[N][N], int row, int col, int num){
  int rowFactor = row - (row % 3);
  int colFactor = col - (col % 3);
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(grid[i+rowFactor][j+colFactor] == num){
        return false;
      }
    }
  }
  return true;
}

bool isPossible(int grid[N][N], int row, int col, int num){
  return (checkRow(grid, row, num) && checkCol(grid, col, num) && checkBox(grid, row, col, num));
}

bool findEmpty(int grid[N][N], int &row, int &col){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(grid[i][j] == 0){
        row = i;
        col = j;
        return true;
      }
    }
  }
  return false;
}

bool sudokuSolver(int grid[N][N]){
  int row , col;
  if(!findEmpty(grid, row, col)){
    return true;
  }
  for(int i = 1; i <= N; i++){
    if(isPossible(grid, row, col, i)){
      grid[row][col] = i;
      if(sudokuSolver(grid)){
        return true;
      }
      grid[row][col] = 0;
    }
  }
  return false;
}

int main(){
  int grid[N][N];
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> grid[i][j];
    }
  }
  sudokuSolver(grid);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
