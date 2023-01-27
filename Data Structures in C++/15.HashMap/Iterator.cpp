#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
#include<string>
using namespace std;

int main(){
  //--------------------Unordered Map-------------------------------------//
  unordered_map<string, int> unorderedMap;
  unorderedMap["abc1"] = 1;
  unorderedMap["abc2"] = 2;
  unorderedMap["abc3"] = 3;
  unorderedMap["abc4"] = 4;
  unorderedMap["abc5"] = 5;
  unorderedMap["abc6"] = 6;

  unordered_map<string, int>::iterator it = unorderedMap.begin();
  cout << "***Unordered Map***" << endl;
  while(it != unorderedMap.end()){
    cout << "Key : " << it -> first << " Value : " << it -> second << endl;
    it++;
  }

  //-------------------Find-----------------------------------//
  unordered_map<string,int>::iterator it4 = unorderedMap.find("abc1");

  //--------------------Erase---------------------------------//
  unorderedMap.erase(it4);
  unorderedMap.erase(unorderedMap.begin(), unorderedMap.end());
  //--------------------Map-------------------------------------//

  map<string, int> Map;
  Map["def1"] = 1;
  Map["def2"] = 2;
  Map["def3"] = 3;
  Map["def4"] = 4;
  Map["def5"] = 5;
  Map["def6"] = 6;

  map<string, int>::iterator it2 = Map.begin();
  cout << "***Map***" << endl;

  while(it2 != Map.end()){
    cout << "Key : " << it2 -> first << " Value : " << it2 -> second << endl;
    it2++;
  }

  //--------------------Vector-------------------------------------//

  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  v.push_back(6);

  vector<int>::iterator it3 = v.begin();
  cout << "***Vector***" << endl;

  while(it3 != v.end()){
    cout << *it3 << endl;
    it3++;
  }
  return 0;
}
