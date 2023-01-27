/*
Q. Pair Sum

You have been given an integer array/list(ARR) and a number X. Find and return the total number of pairs in the array/list which sum to X.

Note:
Given array/list can contain duplicate elements.

Sample Input 1:
1
9
1 3 6 2 5 4 3 2 4
7

Sample Output 1:
7

Sample Input 2:
2
9
1 3 6 2 5 4 3 2 4
12
6
2 8 10 5 -2 5
10

Sample Output 2:
0
2


Explanation for Input 2:
Since there doesn't exist any pair with sum equal to 12 for the first query, we print 0.

For the second query, we have 2 pairs in total that sum up to 10. They are, (2, 8) and (5, 5).
*/

#include<iostream>
using namespace std;

int pairSum(int arr[], int n, int x){
  int count = 0;
  for(int j = 0; j < n-1; j++){
    for(int k = (j+1); k < n; k++){
      if(arr[j]+arr[k] == x){
        count++;
      }
    }
  }
  return count;
}

int main(){
  int n, x;
  cin >> n;

  int arr[10];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  cin >> x;

  int output = pairSum(arr,n,x);
  cout << output << endl;
}
