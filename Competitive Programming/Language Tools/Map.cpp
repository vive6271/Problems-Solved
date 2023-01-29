#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
  int arr[] = {1,2,3,4,5,6,5};

  cout << "//-------Map--------//" << endl;
  map<int,int> m;
  for(int i = 0; i < 7; i++){
    m[arr[i]]++;
  }
  map<int,int> :: iterator it;
  for(it = m.begin(); it != m.end(); it++){
    cout << it -> first << " : " << it -> second << endl;
  }
  cout << endl;
  m.erase(1);
  for(it = m.begin(); it != m.end(); it++){
    cout << it -> first << " : " << it -> second << endl;
  }

  cout << "//-------Unordered_Map--------//" << endl;
  unordered_map<int,int> um;
  for(int i = 0; i < 7; i++){
    um[arr[i]]++;
  }
  unordered_map<int,int> :: iterator it1;
  for(it1 = um.begin(); it1 != um.end(); it1++){
    cout << it1 -> first << " : " << it1 -> second << endl;
  }
  cout << endl;
  um.erase(1);
  for(it1 = um.begin(); it1 != um.end(); it1++){
    cout << it1 -> first << " : " << it1 -> second << endl;
  }
  return 0;
}
