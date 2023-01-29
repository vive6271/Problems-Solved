#include<bits/stdc++.h>
using namespace std;
#define int long long int

int solve(pair<int,int> *arr, int n){
  int *newArr = new int[n];
  int tmp, sum = 0, ans = LLONG_MAX;
  for(int i = 0; i < n; i++){
    if(i == 0){
      tmp = arr[i].first - arr[n-1].second;
      if(tmp > 0){
        newArr[i] = tmp;
        sum += tmp;
      }else{
        newArr[i] = 0;
      }
      continue;
    }
    tmp = arr[i].first - arr[i-1].second;
    if(tmp > 0){
      newArr[i] = tmp;
      sum += tmp;
    }else{
      newArr[i] = 0;
    }
  }
  for(int i = 0; i < n; i++){
    ans = min(ans, (sum + arr[i].first - newArr[i]));
  }
  delete [] newArr;
  return ans;
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    pair<int,int> *arr = new pair<int,int>[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i].first >> arr[i].second;
    }
    cout << solve(arr, n) << endl;
    delete [] arr;
  }
  return 0;
}

/* TC :- O(N^2)
#include<bits/stdc++.h>
using namespace std;

int solve(pair<int,int> *arr, int index, int n){
  pair<int,int> *newArr = new pair<int,int>[n];
  copy_n(arr, n, newArr);
  int ans = 0;
  for(int i = 1; i <= n; i++){
    if(newArr[index].first > 0){
      ans += newArr[index].first;
      newArr[index].first = 0;
    }
    newArr[(index+1) % n].first -= newArr[index].second;
    index = (index+1) % n;
  }
  delete [] newArr;
  return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    pair<int,int> *arr = new pair<int,int>[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i].first >> arr[i].second;
    }
    int minCount = INT_MAX;
    for(int i = 0; i < n; i++){
      minCount = min(minCount, solve(arr, i, n));
    }
    cout << minCount << endl;
    delete [] arr;
  }
}
*/
