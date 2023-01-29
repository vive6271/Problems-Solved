#include<iostream>
#include<climits>
using namespace std;

/*
// Brute Force
int minimumCost(int **input, int si, int sj, int ei, int ej){
  if(si == ei && sj == ej){
    return input[ei][ej];
  }

  if(si > ei || sj > ej){
    return INT_MAX;
  }

  int option1 = minimumCost(input, si+1, sj, ei, ej);
  int option2 = minimumCost(input, si+1, sj+1, ei, ej);
  int option3 = minimumCost(input, si, sj+1, ei, ej);
  return input[si][sj] + min(option1, min(option2, option3));
}

// Memoization

int minimumCost(int **input, int si, int sj, int ei, int ej, int **output){
  if(si == ei && sj == ej){
    return input[ei][ej];
  }

  if(si > ei || sj > ej){
    return INT_MAX;
  }

  if(output[si][sj] != -1){
    return output[si][sj];
  }
  int option1 = minimumCost(input, si+1, sj, ei, ej, output);
  int option2 = minimumCost(input, si+1, sj+1, ei, ej, output);
  int option3 = minimumCost(input, si, sj+1, ei, ej, output);
  output[si][sj] = input[si][sj] + min(option1, min(option2, option3));
  return output[si][sj];
}

int minimumCost(int **input, int si, int sj, int ei, int ej){
  int **output = new int*[ei+1];
  for(int i = 0; i <= ei; i++){
    output[i] = new int[ej+1];
    for(int j = 0; j <= ej; j++){
      output[i][j] = -1;
    }
  }
  int ans = minimumCost(input, si, sj, ei, ej, output);
  for(int i = 0; i <= ei; i++){
    delete [] output[i];
  }
  delete [] output;
  return ans;
}
*/

int minimumCost(int **input, int m, int n){
  int **output = new int*[m];
  for(int i = 0; i < m; i++){
    output[i] = new int[n];
  }
  output[m-1][n-1] = input[m-1][n-1];
  for(int i = m-2; i >= 0; i--){
    output[i][n-1] = input[i][n-1] + output[i+1][n-1];
  }

  for(int j = n-2; j >= 0; j--){
    output[m-1][j] = input[m-1][j] + output[m-1][j+1];
  }
  for(int i = m-2; i >= 0; i--){
    for(int j = n-2; j >= 0; j--){
      output[i][j] = input[i][j] + min(output[i+1][j], min(output[i+1][j+1],output[i][j+1]));
    }
  }
  int ans = output[0][0];
  for(int i = 0; i < m; i++){
    delete [] output[i];
  }
  delete [] output;
  return ans;
}

int main(){
  int **input = new int*[3];
  input[0] = new int[3];
  input[1] = new int[3];
  input[2] = new int[3];

  input[0][0] = 4;
  input[0][1] = 3;
  input[0][2] = 2;
  input[1][0] = 1;
  input[1][1] = 8;
  input[1][2] = 3;
  input[2][0] = 1;
  input[2][1] = 1;
  input[2][2] = 8;

  //cout << minimumCost(input, 0, 0, 2, 2) << endl;
  cout << minimumCost(input, 3, 3) << endl;
  delete [] input[0];
  delete [] input[1];
  delete [] input[2];
  delete input;
  return 0;
}
