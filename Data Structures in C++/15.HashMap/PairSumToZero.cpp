/*
Q. Pair Sum to 0

Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well.

Sample Input 1:
5
2 1 -2 2 3

Sample Output 1:
2
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int pairSum(int *arr, int n) {
  int ans = 0;
  unordered_map<int, int> freq;
  for(int i = 0; i < n; i++){
    int findNum = 0 - arr[i];
    if(freq.count(findNum) > 0){
      int k = freq[findNum];
      ans += k;
      /*
      while(k--){
        if(findNum < arr[i]){
          cout << findNum << " " << arr[i] << endl;
        }else{
          cout << arr[i] << " " << findNum << endl;
        }
      }
      */
    }
    if(freq.count(arr[i]) > 0){
      freq[arr[i]]++;
      continue;
    }
    freq[arr[i]] = 1;
  }
  return ans;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}
