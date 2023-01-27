/*
Q. Triplet Sum

You have been given a random integer array/list(ARR) and a number X. Find and return the number of triplets in the array/list which sum to X.
Note :
Given array/list can contain duplicate elements.

Sample Input 1:
1
7
1 2 3 4 5 6 7 
12

Sample Output 1:
5

Sample Input 2:
2
7
1 2 3 4 5 6 7 
19
9
2 -5 8 -6 0 5 10 11 -3
10

Sample Output 2:
0
5

Explanation for Input 2:
Since there doesn't exist any triplet with sum equal to 19 for the first query, we print 0.

For the second query, we have 5 triplets in total that sum up to 10. They are, (2, 8, 0), (2, 11, -3), (-5, 5, 10), (8, 5, -3) and (-6, 5, 11)
*/

#include<iostream>
using namespace std;

int pairSum(int arr[], int n, int x){
  int count = 0;
  for(int j = 0; j < n-2; j++){
    for(int k = (j+1); k < n-1; k++){
      for(int l = (k+1); l < n; l++){
        if(arr[j] + arr[k] + arr[l] == x){
          count++;
      }
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
