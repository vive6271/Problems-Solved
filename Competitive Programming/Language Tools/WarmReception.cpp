#include<bits/stdc++.h>
using namespace std;

int main() {
	// Write your code here
  int n;
  cin >> n;
  int *inTime = new int[n];
  int *outTime = new int[n];
  for(int i = 0; i < n; i++){
    cin >> inTime[i];
  }
  for(int i = 0; i < n; i++){
    cin >> outTime[i];
  }
  sort(inTime, inTime+n);
  sort(outTime, outTime+n);
  int chairs = n;
  int j = 0;
  for(int i = 0; i < n; i++){
    if(inTime[i] >= outTime[j]){
      chairs--;
      j++;
    }
  }
  cout << chairs << endl;
  delete [] inTime;
  delete [] outTime;
  return 0;
}
