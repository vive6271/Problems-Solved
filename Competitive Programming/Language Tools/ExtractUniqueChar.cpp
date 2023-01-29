#include <iostream>
#include <string>
#include<unordered_set>
using namespace std;


string uniqueChar(string str) {
	// Write your code here
  unordered_set<char> s;
  string ans;
  for(int i = 0; i < str.length(); i++){
    if(s.find(str[i]) == s.end()){
      ans += str[i];
      s.insert(str[i]);
    }
  }
  return ans;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}
