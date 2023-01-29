#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> voterList(int *arr, int n){
  vector<int> v;
  sort(arr,arr+n);
  for(int i = 0; i < n;){
    int count = 0;
    int j = i;
    while(j < n && (arr[j] == arr[i])){
      count++;
      j++;
    }
    if(count >= 2){
      v.push_back(arr[i]);
    }
    i = j;
  }
  return v;
}

int main(){
  int n1, n2, n3;
  cin >> n1 >> n2 >> n3;
  int totalN = (n1+n2+n3);
  int *arr = new int[totalN];
  for(int i = 0; i < totalN; i++){
    cin >> arr[i];
  }

  /*
  sort(arr,arr+totalN);
  vector<int> v;
  for(int i = 1; i < totalN; i++){
    if(arr[i-1] == arr[i]){
      v.push_back(arr[i]);
      arr[i-1] = -1;
      arr[i] = -1;
    }
  }
  */
  vector<int> v = voterList(arr, totalN);
  cout << v.size() << endl;
  for(int i = 0; i < v.size(); i++){
    cout << v[i] << endl;
  }
  return 0;
}
