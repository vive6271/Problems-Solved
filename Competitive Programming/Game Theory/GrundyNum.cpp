#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define N 1000001
int helpArr[N];

int findGrundy(int n){
  if(n == 0){
    return 0;
  }
  if(helpArr[n] != -1){
    return helpArr[n];
  }
  int a = findGrundy(n/2);
  int b = findGrundy(n/3);
  int c = findGrundy(n/6);
  int x = 0;
  while(x == a || x == b || x == c){
    x++;
  }
  return helpArr[n] = x;
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  memset(helpArr, -1, sizeof(helpArr));
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    cout << findGrundy(n) << endl;
  }
  return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define N 1000001
int helpArr[N];

void findGrundy(){
  int a, b, c, x;
  helpArr[0] = 0;
  for(int i = 1; i < N; i++){
    a = helpArr[i/2];
    b = helpArr[i/3];
    c = helpArr[i/6];

    x = 0;
    while(x == a || x == b || x == c){
      x++;
    }
    helpArr[i] = x;
  }
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  memset(helpArr, -1, sizeof(helpArr));
  findGrundy();
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    cout << helpArr[n] << endl;
  }
  return 0;
}
*/
