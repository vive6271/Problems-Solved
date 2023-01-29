#include<iostream>
#include<cstring>
#include<map>
using namespace std;

char nonRepeatingCharacter(string str){
  map<char,int> frequency;
  for(int i = 0; i < str.length(); i++){
    frequency[str[i]]++;
  }
  for(int i = 0; i < str.length(); i++){
    if(frequency[str[i]] == 1){
      return str[i];
    }
  }
  return str[0];
}

int main(){
  string str;
  cin >> str;
  cout << nonRepeatingCharacter(str) << endl;
}
