#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll n;
  cin >> n;
  ll *arr = new ll[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  ll currIndex = 0, nextIndex = 0, ans = 0;
  while(currIndex < (n-1)){
    nextIndex = currIndex+1;
    while(nextIndex < (n-1)){
      ll aI = abs(arr[currIndex]), aJ = abs(arr[nextIndex]);
      if((aI > aJ) || ((aI == aJ) && arr[currIndex] > 0)){
        break;
      }
      nextIndex++;
    }
    ans += (((nextIndex - currIndex) * arr[currIndex]) + (((nextIndex*nextIndex) - (currIndex*currIndex)) * (arr[currIndex]*arr[currIndex])));
    currIndex = nextIndex;
  }
  delete [] arr;
  cout << ans << endl;
  return 0;
}
