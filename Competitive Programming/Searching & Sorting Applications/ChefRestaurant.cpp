#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

bool compare(pair<int,int> p1, pair<int,int> p2){
  return p1.first < p2.first;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    ll n, m;
    cin >> n >> m;
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++){
      pair<int,int> p;
      cin >> p.first >> p.second;
      v.push_back(p);
    }
    sort(v.begin(),v.end(),compare);
    vector<pair<int,int>> :: iterator index;
    for(int i = 0; i < m; i++){
      int a;
      cin >> a;
      pair<int,int> p1;
      p1.first = a;
      index = lower_bound(v.begin(), v.end(), p1);
      if(index == v.begin()){
        cout << ((index -> first) - a) << endl;
      }else if(index == v.end()){
        index--;
        if(index -> first <= a && index -> second > a){
          cout << "0" << endl;
        }else{
          cout << "-1" << endl;
        }
      }else{
        if(index -> first == a){
          cout << "0" << endl;
        }else{
          index--;
          if(index -> first <= a && index -> second > a){
            cout << "0" << endl;
          }else{
            index++;
            cout << ((index -> first) - a) << endl;
          }
        }
      }
    }
  }
}
