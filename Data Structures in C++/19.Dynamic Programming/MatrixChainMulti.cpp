/*
Q. Matrix Chain Multiplication

Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices. 
In other words, determine where to place parentheses to minimize the number of multiplications.

You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. 
You need to find minimum number of multiplications needed to multiply the chain.

Sample Input 1:
3
10 15 20 25

Sample Output 1:
8000

Sample Output Explanation:

There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If we multiply in order- A1*(A2*A3), then number of multiplications required are 11250.
If we multiply in order- (A1*A2)*A3, then number of multiplications required are 8000.
Thus minimum number of multiplications required are 8000. 

*/
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

/*
//-----------Brute Force---------------------//

int matrixChainMultiplication(int *arr, int start, int end){
    if(start == end || start == end-1){
        return 0;
    }
    int ans = INT_MAX;
    for(int k = start+1; k < end; k++){
        int tmpAns = matrixChainMultiplication(arr, start, k) + matrixChainMultiplication(arr, k, end) + (arr[start] * arr[k] * arr[end]);
        ans = min(ans, tmpAns);
    }
    return ans;
}

int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
    return matrixChainMultiplication(arr, 0, n);
}
*/

int matrixChainHelper(int *arr, int **output, int start, int end){
  if(start == end || start == end-1){
    return 0;
  }
  if(output[start][end] != -1){
    return output[start][end];
  }
  int ans = INT_MAX;
  for(int k = start+1; k < end; k++){
    int tmp = matrixChainHelper(arr, output,start,k) + matrixChainHelper(arr,output,k,end) + (arr[start] * arr[k] * arr[end]);
    ans = min(ans,tmp);
  }
  output[start][end] = ans;
  return ans;
}

int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
    int **output = new int*[n+1];
    for(int i = 0; i <= n; i++){
      output[i] = new int[n+1];
      for(int j = 0; j <= n; j++){
        output[i][j] = -1;
      }
    }
    int ans = matrixChainHelper(arr, output, 0, n);
    for(int i = 0; i <= n; i++){
      delete [] output[i];
    }
    delete [] output;
    return ans;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}
