#include<iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
  unordered_map<string, int> ourMap;

  //Insert
  pair<string, int> p("abc", 1);
  ourMap.insert(p);
  ourMap["def"] = 2;

  //Find or Access
  cout << ourMap["abc"] << endl;
  cout << ourMap.at("abc") << endl;

  //cout << ourMap.at("ghi") << endl;
  cout << "Size : " << ourMap.size() << endl;
  cout << ourMap["ghi"] << endl;
  cout << "Size : " << ourMap.size() << endl;

  //Check Presence
  if(ourMap.count("ghi") > 0){
    cout << "ghi is Present" << endl;
  }

  //Erase
  ourMap.erase("ghi");
  cout << "Size : " << ourMap.size() << endl;
  if(ourMap.count("ghi") > 0){
    cout << "ghi is Present" << endl;
  }
  return 0;
}
