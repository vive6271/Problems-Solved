/*
Q. Maximum Frequency Number

You are given an array of integers that contain numbers in random order. 
Write a program to find and return the number which occurs the maximum times in the given input.

If two or more elements contend for the maximum frequency, return the element which occurs in the array first.

Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 

Sample Output 1 :
2

Sample Input 2 :
3
1 4 5

Sample Output 2 :
1
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


/*
int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int,int> map;
    vector<int> key;
    for(int i = 0; i < n; i++){
        ++map[arr[i]];
        key.push_back(arr[i]);
    }
    int max = arr[0];
    for(int i = 1; i < key.size(); i++){
        if(map[max] < map[key[i]]){
            max = key[i];
        }
    }
    return max;
}
*/
int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int, int> highMap;
    vector<int> key;
    for(int i = 0; i < n; i++){
      if(highMap.count(arr[i]) > 0){
        highMap[arr[i]]++;
        continue;
      }
      highMap[arr[i]] = 1;
      key.push_back(arr[i]);
    }
    int max = arr[0];
    for(int i = 1; i < key.size(); i++){
      if(highMap[max] < highMap[key[i]]){
        max = key[i];
      }
    }
    return max;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}
