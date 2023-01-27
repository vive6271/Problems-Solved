/*
Q. Subset Sum

You are given an array of integers and a target K. You have to find the count of subsets of the given array that sum up to K.

Note:
1. Subset can have duplicate values.
2. Empty subset is a valid subset and has sum equal to zero.

Sample Input 1:
1
5 6
2 4 4 3 1

Sample Output 1:
3

Explanation:
Following are the three subsets, that sum upto K=6:
1. [2, 4], Element 4 in this subset is the one at index 1
2. [2, 4], Element 4 in this subset is the one at index 2
3. [2, 3, 1]  

Sample Input 2:
2
8 8
1 4 1 3 1 1 2 3 
8 2
4 1 4 4 2 4 1 1

Sample Output 2:
30
4

*/

#include <bits/stdc++.h>
using namespace std;

int subsetSum(int *arr, int size, int sum){
  if(size == 0){
    if(sum == 0){
      return 1;
    }
    return 0;
  }
  return subsetSum(arr+1, size-1, sum) + subsetSum(arr+1, size-1, (sum-arr[0]));
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, x;
    cin >> n >> x;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }
    cout << subsetSum(arr, n, x) << endl;
  }
  return 0;
}
