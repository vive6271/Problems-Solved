#include <iostream>
#include <unordered_map>
using namespace std;

int pairSum(int *arr, int n) {
	// Write your code here
  unordered_map<int,int> Map;
  int pairCount = 0;
  for(int i = 0; i < n; i++){
    int findNum = -1 * arr[i];
    if(Map.find(findNum) != Map.end()){
      pairCount += Map[findNum];
    }
    Map[arr[i]]++;
  }
  return pairCount;
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
