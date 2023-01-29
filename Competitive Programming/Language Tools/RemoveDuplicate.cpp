#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
/*
vector<int> *removeDuplicate(vector<int> input){
  set<int> s;
  vector<int> *newOutput = new vector<int>();
  for(int i = 0; i < input.size(); i++){
    if(s.find(input[i]) == s.end()){
      s.insert(input[i]);
      newOutput -> push_back(input[i]);
    }
  }
  return newOutput;
}
*/

vector<int> *removeDuplicate(vector<int> input){
  vector<int> *newOutput = new vector<int>();
  sort(input.begin(),input.end());
  newOutput -> push_back(input[0]);
  for(int i = 1; i < input.size(); i++){
    if(input[i] != input[i-1]){
      newOutput -> push_back(input[i]);
    }
  }
  return newOutput;
}

int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < v.size(); i++){
    cin >> v[i];
  }
  vector<int> *output = removeDuplicate(v);
  for(int i = 0; i < output -> size(); i++){
    cout << output -> at(i) << " ";
  }
  cout << endl;
  delete output;
  return 0;
}
