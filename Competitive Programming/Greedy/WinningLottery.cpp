#include<bits/stdc++.h>
using namespace std;

string winningLottery(int s, int d){
  string str;
  s--;
  for(int i = 0; i < d-1; i++){
    if(s >= 9){
      str = ("9") + str;
      s -= 9;
    }else{
      str = to_string(s) + str;
      s = 0;
    }
  }
  str = to_string(s+1) + str;
  return str;
}

void winningLottery(int s, int d){
  int *arr = new int[d];
  s--;
  for(int i = d-1; i > 0; i--){
    if(s >= 9){
      arr[i] = 9;
      s -= 9;
    }else{
      arr[i] = s;
      s = 0;
    }
  }
  arr[0] = s+1;
  for(int i = 0; i < d; i++){
    cout << arr[i];
  }
  cout << endl;
  delete [] arr;
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int s, d;
    cin >> s >> d;
    winningLottery(s,d);
    //cout << winningLottery(s,d) << endl;
  }
  return 0;
}
