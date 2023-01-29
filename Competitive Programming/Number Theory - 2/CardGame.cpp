#include<iostream>
#include<vector>
using namespace std;
#define int long long int

int cardGame(int *arr, int n, int k){
  vector<pair<int,int>> vP;
  int num = k;
  for(int i = 2; i*i <= num; i++){
    if(num % i == 0){
      int count = 0;
      while(num % i == 0){
        count++;
        num /= i;
      }
      vP.push_back(make_pair(i,count));
    }
  }
  if(num != 1){
    vP.push_back(make_pair(num,1));
  }
  vector<pair<int,int>> vQ = vP;
  for(int i = 0; i < vQ.size(); i++){
    vQ[i].second = 0;
  }

  int index = 0, ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < vP.size(); j++){
      if(arr[i] % vP[j].first == 0){
        num = arr[i];
        int count = 0;
        while(num % vP[j].first == 0){
          count++;
          num /= vP[j].first;
        }
        vQ[j].second += count;
      }
    }

    while(index <= i){
      int j;
      for(j = 0; j < vP.size(); j++){
        if(vP[j].second > vQ[j].second){
          break;
        }
      }
      if(j != vP.size()){
        break;
      }
      ans += n-i;

      for(int j = 0; j < vP.size(); j++){
        if(arr[index] % vP[j].first == 0){
          num = arr[index];
          int count = 0;
          while(num % vP[j].first == 0){
            count++;
            num /= vP[j].first;
          }
          vQ[j].second -= count;
        }
      }
      index++;
    }
  }
  return ans;
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k;
  cin >> n >> k;
  int *arr = new int[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  cout << cardGame(arr,n,k) << endl;
  delete [] arr;
  return 0;
}
