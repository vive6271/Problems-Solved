/*
Q. Loot Houses

A thief wants to loot houses. He knows the amount of money in each house. 
He cannot loot two consecutive houses. Find the maximum amount of money he can loot.

Sample Input 1 :
6
5 5 10 100 10 5

Sample Output 1 :
110

Sample Input 2 :
6
10 2 30 20 3 50

Sample Output 2 :
90

Explanation of Sample Output 2 :
Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all the other possible combinations would result in less than 90.
*/

#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

//-----------Brute Force---------------------//
/*
int maxMoneyLooted(int *arr, int n){
	//Write your code here
	if(n <= 0){
		return 0;
	}
	int a = maxMoneyLooted(arr+1, n-1);
	int b = arr[0] + maxMoneyLooted(arr+2, n-2);
	return max(a,b);
}

//Memoization

int maxMoneyLooted(int *arr, int n, int *output){
	//Write your code here
	if(n <= 0){
		return 0;
	}
	if(output[n] != -1){
		return output[n];
	}
	int a = maxMoneyLooted(arr+1, n-1, output);
	int b = arr[0] + maxMoneyLooted(arr+2, n-2, output);
	output[n] = max(a,b);
	return output[n];
}

int maxMoneyLooted(int *arr, int n){
	int *output = new int[n+1];
	for(int i = 0; i <= n; i++){
		output[i] = -1;
	}
	int ans = maxMoneyLooted(arr, n, output);
	delete [] output;
	return ans;
}

*/

int maxMoneyLooted(int *arr, int n){
	//Write your code here
	int *output = new int[n+1];
	output[0] = 0;
	output[1] = arr[0];
	for(int i = 2; i <= n; i++){
		int a = output[i-1];
		int b = INT_MIN;
		if(i >= 2){
			b = arr[i-1] + output[i-2];
		}
		output[i] = max(a,b);
	}
	int ans = output[n];
	delete [] output;
	return ans;
}

int main(){
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << maxMoneyLooted(arr, n);
	delete[] arr;
}
