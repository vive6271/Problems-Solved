#include<iostream>
#include<vector>
using namespace std;

int main(){
  vector<int> v1(5);
  for(int i = 0; i < v1.size(); i++){
    v1[i] = i+1;
  }
  vector<int> :: iterator it;
  for(it = v1.begin(); it != v1.end(); it++){
    cout << *it << " ";
  }
  cout << endl;

  vector<int> v2;
  for(int i = 0; i < 5; i++){
    v2.push_back(i+1);
  }
  vector<int> :: iterator it2;
  for(it2 = v2.begin(); it2 != v2.end(); it2++){
    cout << *it2 << " ";
  }
  cout << endl;
}
