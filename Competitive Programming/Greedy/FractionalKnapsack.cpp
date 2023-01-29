#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool compare(pair<pair<int,int>,double> p1, pair<pair<int,int>,double> p2){
  return (p1.second > p2.second);
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, w, value, weight;
  cin >> n >> w;
  pair<pair<int,int>,double> *arr = new pair<pair<int,int>,double>[n];

  for(int i = 0; i < n; i++){
    cin >> value >> weight;
    arr[i].first.first = value;
    arr[i].first.second = weight;
    arr[i].second = ((double) value / weight);
  }
  sort(arr, arr+n, compare);
  int i = 0;
  double totalValue = 0.0;
  while(w && i < n){
    if(w >= arr[i].first.second){
      totalValue += arr[i].first.first;
      w -= arr[i].first.second;
      i++;
    }else{
      totalValue += w * arr[i].second;
      w = 0;
    }
  }
  cout << fixed << setprecision(6) << totalValue << endl;
  delete [] arr;
  return 0;
}
