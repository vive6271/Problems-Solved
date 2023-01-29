#include<iostream>
using namespace std;

int minimumStartingIndex(vector<int> &gas, vector<int> &cost, int n) {
    // Write your code here.
    for(int i = 0; i < n; i++){
      if(gas[i] >= cost[i]){
        int j = 0, totalCost = 0;
        for(j = i; j < (i+n); j++){
          int index = j % n;
          totalCost += gas[index] - cost[index];
          if(totalCost < 0){
            i = index;
            break;
          }
        }
        if(totalCost >= 0){
          return i;
        }else if(j == i+n){
          return -1;
        }
      }
    }
    return -1;
}

int minimumStartingIndex(vector<int> &gas, vector<int> &cost, int n) {
    // Write your code here.
    int ans = 0, pValue = 0, nValue = 0;
    for(int i = 0; i < n; i++){
      pValue += gas[i] - cost[i];
      if(pValue < 0){
        ans = i+1;
        nValue += pValue;
        pValue = 0;
      }
    }
    if((pValue+nValue) >= 0){
      return ans;
    }
    return -1;
}



int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<int> gas(n), cost(n);
    for(int i = 0 ; i < n; i++){
      cin >> gas[i];
    }
    for(int i = 0; i < n; i++){
      cin >> cost[i];
    }
    cout << minimumStartingIndex(gas, cost, n) << endl;
  }
  return 0;
}
