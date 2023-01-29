#include <bits/stdc++.h>
using namespace std;

int boredom(int *arr, int n){
  int *freq = new int[1001];
  int *output = new int[1001];
  for(int i = 0; i <= 1000; i++){
    freq[i] = 0;
    output[i] = 0;
  }
  for(int i = 0; i < n; i++){
    freq[arr[i]]++;
  }
  output[0] = 0;
  output[1] = freq[1];
  for(int i = 2; i <= 1000; i++){
    output[i] = max(output[i-2] + (i * freq[i]), output[i-1]);
  }
  int ans = output[1000];
  delete [] freq;
  delete [] output;
  return ans;
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
    cout << boredom(arr,n) << endl;
    delete [] arr;
  }
  return 0;
}
