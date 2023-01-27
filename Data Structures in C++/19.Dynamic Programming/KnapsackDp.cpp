/*
Q. Knapsack (DP)

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
using namespace std;

int knapsack(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
	int **output = new int*[n+1];
	for(int i = 0; i <= n; i++){
		output[i] = new int[maxWeight+1];
	}
	for(int i = 0; i <= n; i++){
		output[i][0] = 0;
	}
	for(int j = 1; j <= maxWeight; j++){
		output[0][j] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= maxWeight; j++){
			int a = output[i-1][j];
			int b = INT_MIN;
			if(j >= weight[i-1]){
				b = value[i-1] + output[i-1][j-weight[i-1]];
			}
			output[i][j] = max(a,b);
		}
	}
	return output[n][maxWeight];
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