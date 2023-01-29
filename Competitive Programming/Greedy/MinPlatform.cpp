#include<bits/stdc++.h>
using namespace std;

/* priority_queue
int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    priority_queue<int, vector<int>, greater<int>> p;
    sort(at,at+n);
    sort(dt,dt+n);
    p.push(dt[0]);
    int ans = 1, platformCount = p.size();
    for(int i = 1; i < n; i++){
      if(at[i] > p.top()){
        p.pop();
        p.push(dt[i]);
      }else{
        p.push(dt[i]);
        platformCount++;
      }
      //platformCount = p.size();
      ans = max(ans, platformCount);
    }
    return ans;
}
//Sotring
int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    int ans = 1, platformCount = 1, i = 1, j = 0;
    sort(at,at+n);
    sort(dt,dt+n);
    while(i < n && j < n){
      if(at[i] <= dt[j]){
        i++;
        platformCount++;
      }else{
        j++;
        platformCount--;
      }
      if(ans < platformCount){
        ans = platformCount;
      }
    }
    return ans;
}
*/
#define N 2361

int calculateMinPatforms(int at[], int dt[], int n){
  int arr[N] = {0};
  for(int i = 0; i < n; i++){
    arr[at[i]]++;
    arr[dt[i]+1]--;
  }
  int ans = 1, sum = 0;
  for(int i = 0; i < N; i++){
    sum += arr[i];
    if(ans < sum){
      ans = sum;
    }
  }
  return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int *at = new int[n];
    int *dt = new int[n];
    for(int i = 0; i < n; i++){
      cin >> at[i];
    }

    for(int i = 0; i < n; i++){
      cin >> dt[i];
    }
    cout << calculateMinPatforms(at, dt, n) << endl;
  }
  return 0;
}
