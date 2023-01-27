#include<iostream>
#include<vector>
using namespace std;

int main(){
  vector<int> v;

  for(int i = 0; i < 5; i++){
    v.push_back(i+1);
  }

  for(int i = 0; i < v.size(); i++){
    cout << v[i] << endl;
  }

  v.pop_back();

  cout << "\nPop Back\n" << endl;
  for(int i = 0; i < v.size(); i++){
    cout << v[i] << endl;
  }

  cout << "*** Size & Cap check ***" << endl;

  vector<int> v1;

  for(int i = 0; i < 10; i++){
    cout << "Cap : " << v1.capacity() << endl;
    v1.push_back(i+1);
    cout << "Size : " << v1.size() << endl;
  }

  return 0;
}
