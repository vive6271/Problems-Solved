/*
Q. Triplet sum

You have been given a random integer array/list(ARR) and a number X. Find and return the triplet(s) in the array/list which sum to X.

Note :
Given array/list can contain duplicate elements.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains an integer 'X'.

Output format :
For each test case, print the total number of triplets present in the array/list.

Output for every test case will be printed in a separate line.

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

void mergeHelper(int *arr, int startIndex, int midIndex, int endIndex){
  int i = startIndex, j = midIndex+1, k = 0;
  int size = (endIndex - startIndex + 1);

  int *array = new int[size];
  while(i <= midIndex && j <= endIndex){
    if(arr[i] < arr[j]){
      array[k] = arr[i];
      i++;
      k++;
    }else{
      array[k] = arr[j];
      j++;
      k++;
    }
  }
  while(i <= midIndex){
    array[k] = arr[i];
    i++;
    k++;
  }
  while(j <= endIndex){
    array[k] = arr[j];
    j++;
    k++;
  }
  int m = 0;
  for(int a = startIndex; a <= endIndex; a++){
    arr[a] = array[m];
    m++;
  }
  delete [] array;
}

void helperSort(int *arr, int startIndex, int endIndex){
  if(startIndex >= endIndex){
    return;
  }
  int mid = (startIndex + endIndex) / 2;
  helperSort(arr, startIndex, mid);
  helperSort(arr, mid+1, endIndex);
  mergeHelper(arr, startIndex, mid, endIndex);
}

int tripletSum(int *arr, int n, int num){
  helperSort(arr,0,n-1);
  int ans = 0;
  for(int i = 0; i < n; i++){
    int target = num - arr[i];
    int startPoint = i+1;
    int endPoint = n-1;

    while(startPoint < endPoint){
      int sum = arr[startPoint] + arr[endPoint];
      if(sum < target){
        startPoint++;
      }else if(sum > target){
        endPoint--;
      }else{
        int initialLeftElement = arr[startPoint], initialLeftIndex = startPoint;
        while (startPoint < endPoint && arr[startPoint] == initialLeftElement) {
            startPoint++;
        }

        // Find the frequency of arr[j]
        int initialRightElement = arr[endPoint], initialRightIndex = endPoint;
        while (endPoint >= startPoint && arr[endPoint] == initialRightElement) {
            endPoint--;
        }

        // If arr[i] and arr[j] are the same
        // then it gets counted twice so subtract 1
        if (initialLeftElement == initialRightElement) {
            int equalNumbers = (startPoint - initialLeftIndex) + (initialRightIndex - endPoint) - 1;
            ans += (equalNumbers * (equalNumbers + 1)) / 2;
        }
        else{
            ans += ((startPoint - initialLeftIndex) * (initialRightIndex - endPoint));
        }
      }
    }
  }
  return ans;
}

int main(){
  int t;
  cin >> t;

  while(t--){
    int size;
    int x;
    cin >> size;

    int *input = new int[size];
    for(int i = 0; i < size; i++){
      cin >> input[i];
    }
    cin >> x;
    cout << tripletSum(input,size,x) << endl;
    delete [] input;
  }
  return 0;
}
