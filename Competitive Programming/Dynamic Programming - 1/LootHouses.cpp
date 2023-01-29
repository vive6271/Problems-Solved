#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

//-----------Brute Force---------------------//
/*
int maxMoneyLooted(int *arr, int n){
	//Write your code here
  if(n <= 0){
    return 0;
  }
  int a = arr[0] + maxMoneyLooted(arr+2, n-2);
  int b = maxMoneyLooted(arr+1, n-1);
  return max(a,b);
}
*/

int maxLoot(int *arr, int n){
    int *output = new int[n];
    output[0] = arr[0];
    output[1] = max(arr[0],arr[1]);
    for(int i = 2; i < n; i++){
        output[i] = max(arr[i]+output[i-2],output[i-1]);
    }
    int ans = output[n-1];
    delete [] output;
    return ans;
}

int main(){
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << maxMoneyLooted(arr, n);
	delete[] arr;
}
