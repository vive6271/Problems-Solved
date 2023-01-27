#include <iostream>
#include "OurMap.h"
using namespace std;

int main(){
  OurMap<int> Map;
  for(int i = 0; i < 10; i++){
    char c = '0' + i;
    string key = "abc";
    key += c;
    int value = i+1;
    Map.insert(key,value);
    cout << Map.getLoadFactor() << endl;
  }

  cout << Map.size() << endl;
  Map.remove("abc2");
  Map.remove("abc7");
  cout << Map.size() << endl;

  for(int i = 0; i < 10; i++){
    char c = '0' + i;
    string key = "abc";
    key += c;
    cout << key << " : " << Map.getValue(key) << endl;
  }
  cout << Map.size() << endl;
}
