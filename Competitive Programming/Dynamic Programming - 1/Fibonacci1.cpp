#include<iostream>
using namespace std;
//Memoization
int fib_helper(int *arr, int n){
  if(n <= 1){
    return n;
  }
  //Check if output already exists
  if(arr[n] != -1){
    return arr[n];
  }
  int fib1 = fib_helper(arr, n-1);
  int fib2 = fib_helper(arr, n-2);
  // Save the output for future use
  arr[n] = fib1+fib2;
  // Return the final output
  return arr[n];
}

int fib(int n){
  int *arr = new int[n+1];
  for(int i = 0; i <= n; i++){
    arr[i] = -1;
  }
  return fib_helper(arr,n);
}

int main(){
  int n;
  cin >> n;
  cout << fib(n) << endl;
  return 0;
}
