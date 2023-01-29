#include <bits/stdc++.h>
using namespace std;
void solve(int arr[], int n){
  // to check the answer
  for (int i = 0; i < n; i++){
    if (abs(arr[i] - i - 1) > 2){
      cout << "NO" << endl;
      return;
    }
  }
  int cnt = 0;
  for (int i = n - 1; i >= 0; i--){
    if (arr[i] != (i + 1)){
      if (((i - 1) >= 0) && arr[i - 1] == (i + 1)){
        cnt++;
        swap(arr[i], arr[i - 1]);
      }else if (((i - 2) >= 0) && arr[i - 2] == (i + 1)){
        cnt += 2;
        arr[i - 2] = arr[i - 1];
        arr[i - 1] = arr[i];
        arr[i] = i + 1;
      }else{
        printf("NO\n");
        return;
      }
    }
  }
  printf("YES\n%d\n", cnt);
  return;
}

int main(){
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
      cin >> arr[i];
    }
    solve(arr, n);
  }
}
