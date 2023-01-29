#include<iostream>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, ans = 0;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
      ans ^= arr[i];
    }
    cout << ans << endl;
    delete [] arr;
  }
  return 0;
}
