#include <iostream>
using namespace std;

/* 1st method (too slow)
void rotate(int *input, int d, int n){
    //Write your code here
    while(d--){
      int tmp = input[0];
      for(int i = 1; i < n; i++){
        input[i-1] = input[i];
      }
      input[n-1] = tmp;
    }
}
2nd method (fast)
void rotate(int *input, int d, int n){
    //Write your code here
    int *arr = new int[d];
    for(int i = 0; i < d; i++){
      arr[i] = input[i];
    }
    for(int i = d; i < n; i++){
      input[i-d] = input[i];
    }
    int k = 0;
    for(int i = n-d; i < n; i++){
      input[i] = arr[k];
      k++;
    }
    delete [] arr;
}

*/
void rotateArray(int *arr, int n){
  int mid = n/2;
  for(int i = 0; i < mid; i++){
    int tmp = arr[i];
    arr[i] = arr[n-i-1];
    arr[n-i-1] = tmp;
  }
}

void rotate(int *input, int d, int n){
    //Write your code here
    rotateArray(input,n);
    rotateArray(input, n-d);
    rotateArray(input+(n-d), d);
}

int main(){
	int t;
	cin >> t;

	while (t--){
		int size;
		cin >> size;
		int *input = new int[size];
		for (int i = 0; i < size; ++i){
			cin >> input[i];
		}
		int d;
		cin >> d;
		rotate(input, d, size);
		for (int i = 0; i < size; ++i){
			cout << input[i] << " ";
		}
		delete[] input;
		cout << endl;
	}
	return 0;
}
