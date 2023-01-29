#include<iostream>
using namespace std;
#define int long long
int mod = 1000000000 + 7;

/*
// Brute Force
int coinChange(int *arr, int size, int v){
  if(size == 0){
    return 0;
  }
  if(v == 0){
    return 1;
  }
  if(v < 0){
    return 0;
  }
  int first = coinChange(arr,size, v - arr[0]);
  int second = coinChange(arr+1,size-1,v);
  return (first+second) % mod;
}


// Memoization


int coinChange(int *arr, int size, int v, int **output){
  if(size == 0){
    return 0;
  }
  if(v == 0){
    return 1;
  }
  if(v < 0){
    return 0;
  }
  if(output[v][size] != -1){
    return output[v][size];
  }
  int first = coinChange(arr,size, v - arr[0],output);
  int second = coinChange(arr+1,size-1,v,output);
  output[v][size] = (first+second) % mod;
  return output[v][size];
}

int coinChange(int *arr, int size, int v){
  int **output = new int*[v+1];
  for(int i = 0; i <= v; i++){
    output[i] = new int[size+1];
    for(int j = 0; j <= size; j++){
      output[i][j] = -1;
    }
  }
  int ans = coinChange(arr,size,v,output);
  for(int i = 0; i <= v; i++){
    delete [] output[i];
  }
  delete [] output;
  return ans;
}

*/

int coinChange(int *arr, int size, int v){
  int **output = new int*[v+1];
  for(int i = 0; i <= v; i++){
    output[i] = new int[size];
  }
  for(int j = 0; j < size; j++){
    output[0][j] = 1;
  }
  for(int i = 1; i <= v; i++){
    for(int j = 0; j < size; j++){
      int x = (i-arr[j] >= 0) ? output[i-arr[j]][j] : 0;
      int y = (j > 0) ? output[i][j-1] : 0;
      output[i][j] = (x+y) % mod;
    }
  }
  int ans = output[v][size-1];
  for(int i = 0; i <= v; i++){
    delete [] output[i];
  }
  delete [] output;
  return ans;
}

int32_t main(){
  int t;
  cin >> t;
  while(t--){
    int n, v;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }
    cin >> v;
    cout << coinChange(arr,n,v) << endl;
  }
  return 0;
}
