#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
int findDuplicate(int *arr, int n){
    //Write your code here
		unordered_map<int,bool> Map;
		for(int i = 0; i < n; i++){
			if(Map[arr[i]] == true){
				return arr[i];
			}
			Map[arr[i]] = true;
		}
		return 0;
}

int findDuplicate(int *arr, int n){
	sort(arr, arr+n);
	for(int i = 0; i < n-1; i++){
		if(arr[i] == arr[i+1]){
			return arr[i];
		}
	}
	return 0;
}
*/
int findDuplicate(int *arr, int n){
	int ans = 0;
  for(int i = 0; i < n; i++){
      ans = ans ^ arr[i];
  }
  for(int i = 0 ; i <= n-2 ; i++){
      ans = ans ^ i;
  }
  return ans;
}
int main(){
	int t;
	cin >> t;

	while (t--){
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++){
			cin >> input[i];
		}
		cout << findDuplicate(input, size) << endl;
	}
	return 0;
}
