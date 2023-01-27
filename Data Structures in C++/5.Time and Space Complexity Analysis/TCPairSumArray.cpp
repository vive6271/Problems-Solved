/*
Q. Pair sum in array

You have been given an integer array/list(ARR) and a number 'num'. Find and return the total number of pairs in the array/list which sum to 'num'.

Note:
Given array/list can contain duplicate elements. 

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains an integer 'num'.

Output format :
For each test case, print the total number of pairs present in the array/list.

Output for every test case will be printed in a separate line.

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

void merge(int *arr, int start, int mid, int end){
  int i = start, j = mid+1, k = 0;
  int size = (end-start+1);
  int *helpArr = new int[size];
  while(i <= mid && j <= end){
    if(arr[i] < arr[j]){
      helpArr[k++] = arr[i++];
    }else{
      helpArr[k++] = arr[j++];
    }
  }

  while(i <= mid){
    helpArr[k++] = arr[i++];
  }
  while(j <= end){
    helpArr[k++] = arr[j++];
  }
  k = 0;
  for(int i = start; i <= end; i++){
    arr[i] = helpArr[k++];
  }
  delete [] helpArr;
}

void mergeSort(int *arr, int start, int end){
  if(start >= end){
    return;
  }
  int mid = (start+end)/2;
  mergeSort(arr, start, mid);
  mergeSort(arr, mid+1, end);
  merge(arr, start, mid, end);
}

int pairSum(int *arr, int n, int num){
  mergeSort(arr, 0, n-1);
  int ans = 0, i = 0, j = n-1;
  while(i < j){
    if(arr[i] + arr[j] < num){
      i++;
    }else if(arr[i] + arr[j] > num){
      j--;
    }else{
      int initialLeftElement = arr[i], initialLeftIndex = i;
      while(i < j && arr[i] == initialLeftElement){
        i++;
      }
      int initialRightElement = arr[j], initialRightIndex = j;
      while(j >= i && arr[j] == initialRightElement){
        j--;
      }

      if(initialLeftElement == initialRightElement){
        int equalNum = (i - initialLeftIndex) + (initialRightIndex - j) - 1;
        ans += (equalNum * (equalNum+1))/2; 
      }else{
        ans += ((i - initialLeftIndex) * (initialRightIndex - j));
      }
    }
  }
  return ans;
}

int main(){
  int t;
  cin >> t;

  while(t--){
    int size, x;
    cin >> size;
    int *input = new int[size];

    for(int i = 0; i < size; i++){
      cin >> input[i];
    }
    cin >> x;
    cout << pairSum(input, size, x) << endl;
    delete [] input;
  }
  return 0;
}
