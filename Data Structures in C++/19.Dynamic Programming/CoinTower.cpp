/*
Q. Coin Tower

Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. 
Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower. 
The person to make the last move wins the game. Can you find out who wins the game?

Sample Input 1 :
4 2 3

Sample Output 1 :
Whis

Sample Input 2 :
10 2 4

Sample Output 2 :
Beerus

Explanation to Sample Input 1:
Initially, there are 4 coins,  In the first move, Beerus can remove either 1, 2, or 3 coins in all three cases, Whis can win by removing all the remaining coins. 

*/

#include <iostream>
#include <string>
using namespace std;

/* Brute Force
int findWin(int n, int x, int y){
	if(n == 1 || n == x || n == y){
		return 0;
	}
	int a = findWin(n-1, x, y);
	int b = 0, c = 0;
	if(n >= x){
		b = findWin(n-x, x, y);
	}
	if(n >= y){
		c = findWin(n-y, x, y);
	}
	return ((a^1) && (b^1) && (c^1));
}

string findWinner(int n, int x, int y){
	// Write your code here .
	return (findWin(n, x, y) == 0) ? "Beerus" : "Whis";
}

// Memoization

int findWin(int n, int x, int y, int *output){
	if(n == 1 || n == x || n == y){
		return 0;
	}
	if(output[n] != -1){
		return output[n];
	}
	int a = findWin(n-1, x, y, output);
	int b = 0, c = 0;
	if(n >= x){
		b = findWin(n-x, x, y, output);
	}
	if(n >= y){
		c = findWin(n-y, x, y, output);
	}
	output[n] = ((a^1) && (b^1) && (c^1));
	return output[n];
}

string findWinner(int n, int x, int y){
	// Write your code here .
	int *output = new int[n+1];
	for(int i = 0; i <= n; i++){
		output[i] = -1;
	}
	string ans = (findWin(n, x, y, output) == 0) ? "Beerus" : "Whis";
	delete [] output;
	return ans;
}
*/

string findWinner(int n, int x, int y){
	// Write your code here .
	bool *output = new bool[n+1];
	output[0] = true;
	for(int i = 1; i <= n; i++){
		bool a = output[i-1];
		bool b = false, c = false;
		if(i >= x){
			b = output[i-x];
		}
		if(i >= y){
			c =output[i-y];
		}
		output[i] = !(a || b || c);
	}

	string ans = (!output[n]) ? "Beerus" : "Whis";
	delete [] output;
	return ans;
}
int main(){
	int n, x, y;
	cin >> n >> x >> y;
	cout << findWinner(n, x, y);
}
