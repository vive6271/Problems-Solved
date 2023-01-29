#include <iostream>
#include <algorithm>
using namespace std;

int tripletSum(int *arr, int n, int num){
  sort(arr, arr+n);
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

/* Too Bad
int tripletSum(int *input, int size, int x){
  int ans = 0;
  for(int i = 0; i < size-2; i++){
    for(int j = i+1; j < size-1; j++){
      for(int k = j+1; k < size; k++){
        if((input[i]+input[j]+input[k]) == x){
          ans++;
        }
      }
    }
  }
  return ans;
}
*/
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	int t;
	cin >> t;

	while (t--){
		int size;
		int x;
		cin >> size;
		int *input = new int[size];
		for (int i = 0; i < size; i++){
			cin >> input[i];
		}
		cin >> x;
		cout << tripletSum(input, size, x) << endl;
		delete[] input;
	}
	return 0;
}
