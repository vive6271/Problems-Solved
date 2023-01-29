#include<iostream>
#include<climits>
using namespace std;


/*   //Memoization

int knapsackHelper(int *weight, int *value, int n, int totalWeight, int **helpArr){
  if(n == 0 || totalWeight == 0){
    return 0;
  }

  if(helpArr[n][totalWeight] != -1){
    return helpArr[n][totalWeight];
  }

  if(weight[0] > totalWeight){
    return knapsackHelper(weight+1, value+1, n-1, totalWeight, helpArr);
  }
  int a = knapsackHelper(weight+1, value+1, n-1, totalWeight, helpArr);
  int b = value[0] + knapsackHelper(weight+1, value+1, n-1, totalWeight - weight[0], helpArr);
  helpArr[n][totalWeight] = max(a,b);
  return helpArr[n][totalWeight];
}

int knapsack(int *weight, int *value, int n, int totalWeight){
  int **helpArr = new int*[n+1];
  for(int i = 0; i <= n; i++){
    helpArr[i] = new int[totalWeight+1];
    for(int j = 0; j <= totalWeight; j++){
      helpArr[i][j] = -1;
    }
  }
  int ans = knapsackHelper(weight, value, n, totalWeight, helpArr);
  for(int i = 0; i <= n; i++){
    delete [] helpArr[i];
  }
  delete [] helpArr;
  return ans;
}
*/

int knapsack(int *weight, int *value, int n, int totalWeight){
  int **dp = new int*[n+1];
  for(int i = 0; i <= n; i++){
    dp[i] = new int[totalWeight+1];
  }
  for(int i = 0; i <= n; i++){
    dp[i][0] = 0;
  }
  for(int j = 1; j <= totalWeight; j++){
    dp[0][j] = 0;
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= totalWeight; j++){
      int a = dp[i-1][j];
      int b = INT_MIN;
      if(weight[i-1] <= j){
        b = value[i-1] + dp[i-1][j-weight[i-1]];
      }
      dp[i][j] = max(a,b);
    }
  }
  int ans = dp[n][totalWeight];
  for(int i = 0; i <= n; i++){
    delete [] dp[i];
  }
  delete [] dp;
  return ans;
}
int main() {
    int n, totalWeight;
    cin >> n;
    int *weight = new int[n];
    int *value = new int[n];

    for(int i = 0; i < n; i++){
      cin >> weight[i];
    }
    for(int i = 0; i < n; i++){
      cin >> value[i];
    }

    cin >> totalWeight;
    cout << knapsack(weight, value, n, totalWeight) << endl;

    delete [] weight;
    delete [] value;
    return 0;
}
