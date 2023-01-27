/*
Q. Shortest Subsequence

Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.

Note: The input data will be such that there will always be a solution.


Sample Input 1:
babab
babba

Sample Output 1:
3

Explanation:
"aab" is the shortest subsequence which is present in S and absent in V.
*/

#include <iostream>
#include <string>
using namespace std;

int solveHelper(int **arr, string s, string v, int sIndex = 0, int vIndex = 0) {
    // Write your code here
    if(v.length() == vIndex){
      return 1;
    }
    if(s.length() == sIndex){
      return 1001;
    }
    if(arr[sIndex][vIndex] != -1){
      return arr[sIndex][vIndex];
    }
    int a = solveHelper(arr, s, v, sIndex+1, vIndex);
    int vInd = -1;
    for(int i = vIndex; i < v.length(); i++){
      if(v[i] == s[sIndex]){
        vInd = i;
        break;
      }
    }
    if(vInd == -1){
      return 1;
    }
    int b = 1 + solveHelper(arr, s, v, sIndex+1, vInd+1);
    arr[sIndex][vIndex] = min(a,b);
    return arr[sIndex][vIndex];
}

int solve(string s, string v){
  int sLength = s.length(), vLength = v.length();
  int **arr = new int*[sLength];
  for(int i = 0; i < sLength; i++){
    arr[i] = new int[vLength];
    for(int j = 0; j < vLength; j++){
      arr[i][j] = -1;
    }
  }
  int ans = solveHelper(arr,s,v);
  for(int i = 0; i < sLength; i++){
    delete [] arr[i];
  }
  delete [] arr;
  return ans;
}

/*
#include <vector>
int solve(string s, string v){
    int m = s.length();
    int n = v.length();

    vector<vector<int>> output(m+1, vector<int>(n+1));
    vector<vector<int>> next(m, vector<int>(n));
    for(int i = 0; i < m; i++){
        int prev = -1;
        for(int j = n-1; j >= 0; j--){
            if(s[i] == v[j]){
                prev = j;
            }
            next[i][j] = prev;
        }
    }
    for(int i = 0; i <= m; i++){
        output[i][n] = 1;
    }
    for(int j = 0; j <= n; j++){
        output[m][j] = 1001;
    }
    
    for(int i = m-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(next[i][j] == -1){
                output[i][j] = 1;
            }else{
                output[i][j] = min(output[i+1][j], 1+output[i+1][next[i][j]+1]);
            }
        
        }
    }
    return output[0][0];
}
*/
int main() {
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}
