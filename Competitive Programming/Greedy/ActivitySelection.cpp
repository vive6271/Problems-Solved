#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
  if(p1.second == p2.second){
    return (p1.first < p2.first);
  }
  return (p1.second < p2.second);
}

int main(){
  int n;
  cin >> n;
  pair<int,int> *activity = new pair<int,int>[n];
  for(int i = 0; i < n; i++){
    cin >> activity[i].first >> activity[i].second;
  }
  sort(activity, activity+n, compare);
  int count = 0, lastPoint = 1;
  for(int i = 0; i < n; i++){
    if(lastPoint <= activity[i].first){
      count++;
      lastPoint = activity[i].second;
    }
  }
  cout << count << endl;
  delete [] activity;
  return 0;
}
