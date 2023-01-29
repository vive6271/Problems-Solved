#include<bits/stdc++.h>
using namespace std;
int main(){

    // write your code here
    int t;
    cin >> t;
    while(t--){
      int n;
      cin >> n;
      int *arr = new int[n];
      for(int i = 0; i < n; i++){
        cin >> arr[i];
      }
      bool isPossible = true;

      for(int i = 0; i < n-1; i++){
        if(arr[i] > arr[i+1]){
          if(arr[i] - arr[i+1] == 1){
            int tmp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = tmp;
          }else{
            isPossible = false;
            break;
          }
        }
      }
      if(isPossible){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }
    return 0;
}
