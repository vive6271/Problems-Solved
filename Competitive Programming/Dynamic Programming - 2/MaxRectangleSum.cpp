#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int kadane(vector<int> *sum, int n){
  int maxSoFar = INT_MIN, maxEnding = 0;
  for(int i = 0; i < n; i++){
    maxEnding += sum -> at(i);
    if(maxSoFar < maxEnding){
      maxSoFar = maxEnding;
    }
    if(maxEnding < 0){
      maxEnding = 0;
    }
  }
  return maxSoFar;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int m,n;
    cin >> m >> n;
    int **arr = new int*[m];
    for(int i = 0; i < m; i++){
      arr[i] = new int[n];
      for(int j = 0; j < n; j++){
        cin >> arr[i][j];
      }
    }

    int ans = INT_MIN;
    for(int i = 0; i < m; i++){
      vector<int> *sum = new vector<int>(n);
      for(int j = i; j < m; j++){
        for(int k = 0; k < n; k++){
          sum -> at(k) += arr[j][k];
        }
        ans = max(ans, kadane(sum,n));
      }
      delete sum;
    }
    cout << ans << endl;
    for(int i = 0; i < m; i++){
      delete [] arr[i];
    }
    delete [] arr;
  }

  return 0;
}

/* Too Slow O(n^4)
int findSum(int **arr, int top, int bottom, int left, int right){
  int sum = 0;
  for(int i = top; i <= bottom; i++){
    for(int j = left; j <= right; j++){
      sum += arr[i][j];
    }
  }
  return sum;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int m,n;
    cin >> m >> n;
    int **arr = new int*[m];
    for(int i = 0; i < m; i++){
      arr[i] = new int[n];
      for(int j = 0; j < n; j++){
        cin >> arr[i][j];
      }
    }

    int ans = INT_MIN;
    for(int i = 0; i < m; i++){
      for(int j = i; j < m; j++){
        for(int k = 0; k < n; k++){
          for(int l = k; l < n; l++){
            ans = max(ans, findSum(arr, i, j, k, l));
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
*/
