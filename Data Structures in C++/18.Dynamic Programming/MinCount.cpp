/*
Q. Minimum Count

Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. 
The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.

Sample Input 1 :
12

Sample Output 1 :
3

Explanation of Sample Output 1 :

12 can be represented as : 
A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.


Sample Input 2 :
9

Sample Output 2 :
1
*/

#include<iostream>
#include<climits>
#include<cmath>
using namespace std;
// Brute Force
/*
int minCount(int n){
  if(n == 0){
    return 0;
  }
  int a = minCount(n-1);
  int b = INT_MAX, c = INT_MAX;
  for(int i = 1; i*i <= n; i++){
    b = minCount(n-(i*i));
    c = min(b,c);
  }
  return 1+min(a,c);
}

// Memoization

int minCountHelper(int *arr, int n){
  if(n == 0){
    return 0;
  }
  if(arr[n-1] != -1){
    return arr[n-1];
  }
  int a = minCountHelper(arr,n-1);
  int b = INT_MAX, c = INT_MAX;
  for(int i = 1; i*i <= n; i++){
    b = minCountHelper(arr,n-(i*i));
    c = min(b,c);
  }
  arr[n-1] = 1+min(a,c);
  return arr[n-1];
}
int minCount(int n){
  int *arr = new int[n];
  for(int i = 0; i < n; i++){
    arr[i] = -1;
  }
  int result = minCountHelper(arr,n);
  delete [] arr;
  return result;
}
*/
int minCount(int n){
	//Write your code here
	if(n <= 0){
		return n;
	}
	int *arr = new int[n+1];
	arr[0] = 0;
	for(int i = 1; i <= n; i++){
		int a = arr[i-1], b = INT_MAX;
		for(int j = 2; j*j <= i; j++){
			if(j*j <= i){
				b = min(b, arr[i - (j*j)]);
			}else{
				break;
			}
		}
		arr[i] = 1 + min(a,b);
	}
	int ans = arr[n];
	delete [] arr;
	return ans;
}
int main(){
  int n;
  cin >> n;
  cout << minCount(n) << endl;
  return 0;
}
