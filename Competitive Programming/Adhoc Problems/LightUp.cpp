#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, x, y;
  cin >> n >> x >> y;

  string str;
  cin >> str;

  int zeroGroup = 0;
  bool zeroFound = false;

  if(str[0] == '0'){
    zeroGroup++;
    zeroFound = true;
  }

  for(int i = 0; i < n-1; i++){
    if(str[i] == '1' && str[i+1] == '0'){
      zeroGroup++;
      zeroFound = true;
    }
  }

  if(!zeroFound){
    cout << '0' << endl;
  }else{
    cout << (long) ((long) (zeroGroup-1) * min(x,y)) + y << endl;
  }
  return 0;
}
