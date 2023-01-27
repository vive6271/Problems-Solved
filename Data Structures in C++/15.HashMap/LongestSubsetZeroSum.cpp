/*
Q. Longest subset zero sum

Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.

Sample Input 1:
10 
95 -97 -387 -435 -5 -70 897 127 23 284

Sample Output 1:
5

Explanation:
The five elements that form the longest subarray that sum up to zero are: -387, -435, -5, -70, 897 
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    unordered_map<int,int> OurMap;
    int sum = 0, maxLen = 0;
    OurMap[0] = sum;
    for(int i = 0; i < n; i++){
      sum += arr[i];
      if(OurMap.count(sum) > 0){
        int tmpLen = i - OurMap[sum]+1;
        if(maxLen < tmpLen){
          maxLen = tmpLen;
        }
        continue;
      }
      OurMap[sum] = i+1;
    }
    return maxLen;
}
/*
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    unordered_map<int,int> map;
    int sum = 0, ans = 0;
    map[0] = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(map.count(sum) > 0){
            ans = max(ans, (i-map[sum]+1));
            continue;
        }
        map[sum] = i+1;
    }
    return ans;
}
*/

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}
