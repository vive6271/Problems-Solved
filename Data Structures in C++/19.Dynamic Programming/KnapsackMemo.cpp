/*
Q. Knapsack (Memoization)

A thief is robbing a store and can carry a maximal weight of W into his knapsack. 
There are N items and ith item weighs wi and is of value vi. Considering the constraints 
of maximum weight that knapsack can carry, you have to find and return the maximum value that thief can generate by stealing items.

Sample Input 1 :
4
1 2 4 5
5 4 8 6
5

Sample Output 1 :
13
*/

#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int knapsackHelper(int *weights, int *values, int n, int maxWeight, int **output){
	//write your code here
	if(maxWeight == 0 || n == 0){
		return 0;
	}
	if(output[maxWeight][n] != -1){
		return output[maxWeight][n];
	}
	int a = knapsackHelper(weights+1, values+1, n-1, maxWeight, output);
	int b = INT_MIN;
	if(weights[0] <= maxWeight){
		b = values[0] + knapsackHelper(weights+1, values+1, n-1, maxWeight - weights[0], output);
	}
	output[maxWeight][n] = max(a,b);
	return output[maxWeight][n];
}

int knapsack(int *weights, int *values, int n, int maxWeight){
  int **output = new int*[maxWeight+1];
	for(int i = 0; i <= maxWeight; i++){
		output[i] = new int[n+1];
		for(int j = 0; j <= n; j++){
			output[i][j] = -1;
		}
	}
	int ans = knapsackHelper(weights, values, n, maxWeight, output);
  for(int i = 0; i <= maxWeight; i++){
		for(int j = 0; j <= n; j++){
			cout << output[i][j] << " ";
		}
		cout << endl;
    delete [] output[i];
  }
  delete [] output;
  return ans;
}

int main(){
	int n;
	cin >> n;
	int *weights = new int[n];
	int *values = new int[n];
	for (int i = 0; i < n; i++){
		cin >> weights[i];
	}

	for (int i = 0; i < n; i++){
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;
	cout << knapsack(weights, values, n, maxWeight) << endl;
	delete[] weights;
	delete[] values;
}
