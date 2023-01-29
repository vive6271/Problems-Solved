#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    vector<int> ans;
    unordered_map<int, bool> ourMap;
    unordered_map<int, int> index;
    for(int i = 0; i < n; i++){
      index[arr[i]] = i;
      if(ourMap.count(arr[i]) == 0){
        ourMap[arr[i]] = true;
      }
    }
    int startNum = 0, endNum = 0, maxSeqLen = 0;
    for(int i = 0; i < n; i++){
      if(ourMap[arr[i]] == true){
        int minSeqNum = arr[i], maxSeqNum = arr[i], currSeqLen = 0, tmpStart = 0, tmpEnd = 0;
        while(ourMap.count(minSeqNum) > 0){
          tmpStart = minSeqNum;
          minSeqNum--;
          currSeqLen++;
        }
        while(ourMap.count(maxSeqNum) > 0){
          ourMap[maxSeqNum] = false;
          tmpEnd = maxSeqNum;
          maxSeqNum++;
          currSeqLen++;
        }
        if(currSeqLen == maxSeqLen){
          if(index[startNum] > index[tmpStart]){
            startNum = tmpStart;
            endNum = tmpEnd;
          }
        }else if(currSeqLen > maxSeqLen){
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
