/*
Q. Extract Unique characters

Given a string S, you need to remove all the duplicates. That means, the output string should 
contain each character only once. The respective order of characters should remain same, as in the input string.

Sample Input 1 :
ababacd

Sample Output 1 :
abcd

Sample Input 2 :
abcde

Sample Output 2 :
abcde
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string uniqueChar(string str) {
	// Write your code here
  unordered_map<char,bool> ourMap;
  string s = "";
  for(int i = 0; str[i] != '\0'; i++){
    if(ourMap.count(str[i]) > 0){
      continue;
    }
    ourMap[str[i]] = true;
    s += str[i];
  }
  return s;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}
