#include<iostream>
using namespace std;
int N = 1000000;

void cubeFreeNum(int *arr){
  for(int i = 0; i <= N; i++){
    arr[i] = 0;
  }
  arr[1] = 1;
  for(int i = 2; i <= 100; i++){
    if(arr[i] == 0){
      int a = i*i*i;
      for(int j = a; j <= N; j += a){
        arr[j] = -1;
      }
    }
  }
  int k = 2;
  for(int i = 2; i <= N; i++){
    if(arr[i] == 0){
      arr[i] = k++;
    }
  }
}

int main(){
  int t;
  cin >> t;
  int *arr = new int[N+1];
  cubeFreeNum(arr);
  while(t--){
    int n;
    cin >> n;
    if(arr[n] == -1){
      cout << "Not Cube Free" << endl;
    }else{
      cout << arr[n] << endl;
    }
  }
  delete [] arr;
  return 0;
}
