/*
Q. Longest Consecutive Sequence

You are given an array of unique integers that contain numbers in random order. 
You have to find the longest possible sequence of consecutive numbers using the numbers from given array.

You need to return the output array which contains starting and ending element. 
If the length of the longest possible sequence is one, then the output array must contain only single element.

Note:
1. Best solution takes O(n) time.
2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.

Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 

Sample Output 1 :
8 12 

Sample Input 2 :
7
3 7 2 1 9 8 41

Sample Output 2 :
7 9

Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and 
[7, 8, 9], but we should select [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array and therefore, 
the output will be 7 9, as we have to print starting and ending element of the longest consecutive sequence.

Sample Input 3 :
7
15 24 23 12 19 11 16

Sample Output 3 :
15 16

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int getIndex(int *arr, int n, int x){
  int index = -1;
  for(int i = 0; i < n; i++){
    if(arr[i] == x){
      index = i;
      break;
    }
  }
  return index;
}
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    vector<int> ans;
    unordered_map<int, bool> OurMap;
    for(int i = 0; i < n; i++){
      if(OurMap.count(arr[i]) > 0){
        continue;
      }
      OurMap[arr[i]] = true;
    }
    int startNum = 0, endNum = 0, maxSeqLen = 0;
    for(int i = 0; i < n; i++){
      if(OurMap[arr[i]] == true){
        int minSeqNum = arr[i], maxSeqNum = arr[i], currSeqLen = 0, tmpStart = 0, tmpEnd = 0;
        while(OurMap.count(minSeqNum) > 0){
          tmpStart = minSeqNum;
          minSeqNum--;
          currSeqLen++;
        }
        while(OurMap.count(maxSeqNum) > 0){
          OurMap[maxSeqNum] = false;
          tmpEnd = maxSeqNum;
          maxSeqNum++;
          currSeqLen++;
        }
        if(currSeqLen == maxSeqLen){
          if(getIndex(arr,n,startNum) > getIndex(arr,n,tmpStart)){
            startNum = tmpStart;
            endNum = tmpEnd;
            maxSeqLen = currSeqLen;
          }
        }else if((maxSeqLen < currSeqLen)){
          startNum = tmpStart;
          endNum = tmpEnd;
          maxSeqLen = currSeqLen;
        }
      }
    }
    if(startNum == endNum){
      ans.push_back(startNum);
    }else{
      ans.push_back(startNum);
      ans.push_back(endNum);
    }
    return ans;
}
/* Better
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    unordered_map<int,bool> map;
    for(int i = 0; i < n; i++){
        map[arr[i]] = true;
    }
    int seqSize = 0, startSeq = 0, endSeq = 0;
    for(int i = 0; i < n; i++){
        if(map[arr[i]]){
            int tmpSeqSize = 1, tmpSeqStart = arr[i], tmpSeqEnd = arr[i];
            int num = arr[i]+1;
            while(true){
                if(map.count(num) > 0){
                    tmpSeqSize++;
                    tmpSeqEnd = num;
                    map[num] = false;
                }else{
                    break;
                }
                num++;
            }
            if(tmpSeqSize > seqSize){
              seqSize = tmpSeqSize;
              startSeq = tmpSeqStart;
              endSeq = tmpSeqEnd;
            }
        }
    }
    vector<int> ans;
    if(seqSize == 1){
        ans.push_back(startSeq);
        return ans;
    }
    ans.push_back(startSeq);
    ans.push_back(endSeq);
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

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}
