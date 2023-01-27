/*
Q. All possible ways

Given two integers a and b. You need to find and return the count of possible ways in 
which we can represent the number a as the sum of unique integers raise to the power b.

For example: if a = 10 and b = 2, only way to represent 10 as sum of unique integers raised to power 2 is-
10 = 1^2 + 3^2 
Hence, answer is 1.

Note : x^y represents x raise to the power y

Sample Input 1 :
10 2

Sample Output 1 :
1

Sample Input 2 :
100 2

Sample Output 2 :
3

Explanation:
Following are the three ways: 
1. 100 = 10^2
2. 100 = 8^2 + 6^2
3. 100 = 7^2+5^2+4^2+3^2+1^2
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force
int getAllWays(int a, int b, int currNum){
	if(a == 0){
		return 1;
	}
	int count = 0;
	for(int i = currNum; pow(i,b) <= a; i++){
		count += getAllWays(a-pow(i,b), b, i+1);
	}
	return count;
}

int getAllWays(int a, int b) {
	// Write your code here
	return getAllWays(a, b, 1);
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << getAllWays(a, b) << endl;
    return 0;
}
