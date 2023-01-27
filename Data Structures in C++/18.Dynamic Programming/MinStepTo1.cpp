/*
Q. Min Steps to 1

Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 )

Sample Input 1 :
4

Sample Output 1 :
2 

Explanation of Sample Output 1 :
For n = 4
Step 1 :  n = 4 / 2  = 2
Step 2 : n = 2 / 2  =  1 

Sample Input 2 :
7

Sample Output 2 :
3

Explanation of Sample Output 2 :
For n = 7
Step 1 :  n = 7 ­- 1 = 6
Step 2 : n = 6  / 3 = 2 
Step 3 : n = 2 / 2 = 1  

*/

#include<iostream>
#include<cmath>
#include<climits>
using namespace std;


/*
Brute Force
int countMinStepsToOne(int n){
  if(n == 1){
    return 0;
  }
  int a = INT_MAX, b = INT_MAX, c = INT_MAX;
  a = countMinStepsToOne(n-1);
  if(n % 2 == 0){
    b = countMinStepsToOne(n/2);
  }
  if(n % 3 == 0){
    c = countMinStepsToOne(n/3);
  }
  return 1+min( a, min(b,c));
}

// Memoization Method

int minStepHelper(int *arr, int n){
  if(n == 1){
    return 0;
  }
  if(arr[n-1] != -1){
    return arr[n-1];
  }
  int a = INT_MAX, b = INT_MAX, c = INT_MAX;
  a = minStepHelper(arr, n-1);
  if(n % 2 == 0){
    b = minStepHelper(arr, n/2);
  }
  if(n % 3 == 0){
    c = minStepHelper(arr, n/3);
  }
  arr[n-1] = 1+min( a, min(b,c));
  return arr[n-1];
}
int countMinStepsToOne(int n){
  int *arr = new int[n];
  for(int i = 0; i < n; i++){
    arr[i] = -1;
  }
  return minStepHelper(arr,n);
}
*/

// Dynamic Programming

int countMinStepsToOne(int n){
	//Write your code here
	int *arr = new int[n+1];
	arr[0] = 0;
	arr[1] = 0;
	for(int i = 2; i <= n; i++){
		int a = arr[i-1];
		int b = INT_MAX, c = INT_MAX;
		
		if(i%2 == 0){
			b = arr[i/2];
		}
		if(i%3 == 0){
			c = arr[i/3];
		}
		arr[i] = 1 + min(a, min(b,c));
	}
	int ans = arr[n];
	delete [] arr;
	return ans;
}

int main(){
  int n;
  cin >> n;
  cout << countMinStepsToOne(n) << endl;
  return 0;
}
