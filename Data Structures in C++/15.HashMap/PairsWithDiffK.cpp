/*
Q. Pairs with difference K

You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.
Note: Take absolute difference between the elements of the array.

Sample Input 1 :
4 
5 1 2 4
3

Sample Output 1 :
2

Sample Input 2 :
4
4 4 4 4 
0

Sample Output 2 :
6

*/
#include <iostream>
#include <unordered_map>
using namespace std;

int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
  int numPairs = 0;
  unordered_map<int,int> OurMap;
  for(int i = 0; i < n; i++){
    int findNum = arr[i] + k;
    if(OurMap.count(findNum) > 0){
      numPairs += OurMap[findNum];
    }
    findNum = arr[i] - k;
    if(k != 0 && OurMap.count(findNum) > 0){
      numPairs += OurMap[findNum];
    }
    OurMap[arr[i]]++;
  }
  return numPairs;
}
/*
int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
	unordered_map<int,int> map;
	int countPair = 0;
	for(int i = 0; i < n; i++){
		int fNum = arr[i]+k, fNum2 = arr[i]-k;
		if(map.count(fNum) > 0){
			countPair += map[fNum];
		}else if(map.count(fNum2) > 0){
			countPair += map[fNum2];
		}
		map[arr[i]]++;
	}
	return countPair;
}
*/
int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}
