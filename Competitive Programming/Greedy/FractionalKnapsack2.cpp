#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Item{
  int value;
  int weight;
};

bool compare(struct Item i1, struct Item i2){
  double value1 = ((double) i1.value) / (i1.weight);
  double value2 = ((double) i2.value) / (i2.weight);
  return value1 > value2;
}

double fractionalKnapsack(struct Item *arr, int n, int w){
  sort(arr, arr+n, compare);

  int currWeight = 0;
  double fValue = 0;
  for(int i = 0; i < n; i++){
    if(currWeight + arr[i].weight <= w){
      currWeight += arr[i].weight;
      fValue += arr[i].value;
    }else{
      int rWeight = w - currWeight;
      fValue += arr[i].value * ((double) rWeight / arr[i].weight);
      break;
    }
  }
  return fValue;
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, w;
  cin >> n >> w;
  Item *arr = new Item[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i].value >> arr[i].weight;
  }
  cout << fixed << setprecision(6) << fractionalKnapsack(arr,n,w) << endl;
  delete [] arr;
  return 0;
}
