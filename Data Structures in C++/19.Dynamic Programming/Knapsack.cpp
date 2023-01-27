/*
Q. Knapsack (Brute Force)

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
/*
int knapsack(int *weights, int *values, int n, int maxWeight){
	//write your code here
	if(maxWeight == 0 || n == 0){
		return 0;
	}
	int a = knapsack(weights+1, values+1, n-1, maxWeight);
	int b = INT_MIN;
	if(weights[0] <= maxWeight){
		b = values[0] + knapsack(weights+1, values+1, n-1, maxWeight - weights[0]);
	}
	return max(a,b);
}
*/
int knapsack(int *weights, int *values, int n, int maxWeight){
	//write your code here
	if(n == 0 || maxWeight == 0){
		return 0;
	}
	if(weights[0] > maxWeight){
		return knapsack(weights+1, values+1, n-1, maxWeight);
	}
	int x = knapsack(weights+1, values+1, n-1, maxWeight);
	int y = knapsack(weights+1, values+1, n-1, maxWeight - weights[0]) + values[0];
	return max(x,y);
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
