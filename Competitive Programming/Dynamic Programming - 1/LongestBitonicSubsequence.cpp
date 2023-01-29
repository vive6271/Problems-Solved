#include<iostream>
using namespace std;

int longestBitonicSubsequence(int *arr, int n){
  int *leftRight = new int[n];
  int *rightLeft = new int[n];
  leftRight[0] = 1;

  // Left To Right Longest Increasing Subsequence
  for(int i = 1; i < n; i++){
    leftRight[i] = 1;
    for(int j = i-1; j >= 0; j--){
      if(arr[j] >= arr[i]){
        continue;
      }

      int possibleAns = leftRight[j]+1;
      if(possibleAns > leftRight[i]){
        leftRight[i] = possibleAns;
      }
    }
  }

  // Right to Letf Longest Increasing Subsequence
  rightLeft[n-1] = 1;
  for(int i = n-2; i >= 0; i--){
    rightLeft[i] = 1;
    for(int j = i+1; j < n; j++){
      if(arr[j] >= arr[i]){
        continue;
      }
      int possibleAns = rightLeft[j]+1;
      if(possibleAns > rightLeft[i]){
        rightLeft[i] = possibleAns;
      }
    }
  }
  int best = 0;
  for(int i = 0; i < n; i++){
    int tmp = leftRight[i]+rightLeft[i]-1;
    if(tmp > best){
      best = tmp;
    }
  }
  delete [] leftRight;
  delete [] rightLeft;
  return best;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }
    cout << longestBitonicSubsequence(arr,n) << endl;
    delete [] arr;
  }
  return 0;
}
