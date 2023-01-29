#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;

char getChar(int i){
  return (char)(i+97);
}

void palindromePrint(string s){
  map<char,vector<int>> indexMap;
  for(int i = 0; i < s.length(); i++){
    indexMap[s[i]].push_back(i);
  }
  int odd_freq_count = 0;
  for(int i = 0; i < 26; i++){
    if(indexMap[getChar(i)].size() % 2 != 0){
      odd_freq_count++;
    }
  }
  if(odd_freq_count >= 2){
    cout << "-1" << endl;
    return;
  }

  int ans[s.length()];
  int start = 0;
  int end = s.length()-1;

  for(int i = 0; i < 26; i++){
    char currentChar = getChar(i);
    for(int j = 0; j < indexMap[currentChar].size(); j += 2){
      if(indexMap[currentChar].size() - j == 1){
        ans[s.length() / 2] = indexMap[getChar(i)][j];
        continue;
      }
      ans[start] = indexMap[currentChar][j];
      ans[end] = indexMap[currentChar][j+1];
      start++;
      end--;
    }
  }
  for(int i = 0; i < s.length(); i++){
    cout << ans[i]+1 << " ";
  }
  cout << endl;
}
/*
void palindromePrint(string str){
  map<char,vector<int>> Map;
  int strLength = str.length();
  for(int i = 0; i < strLength; i++){
    Map[str[i]].push_back(i);
  }

  int oddChar = 0;
  map<char,vector<int>> :: iterator it;
  for(it = Map.begin(); it != Map.end(); it++){
    if((it -> second).size() % 2 == 1){
      oddChar++;
    }
  }
  if(oddChar > 1){
    cout << "-1" << endl;
    return;
  }
  int *arr = new int[strLength];
  int start = 0, end = strLength-1;
  for(it = Map.begin(); it != Map.end(); it++){
    vector<int> tmp = it -> second;
    for(int j = 0; j < tmp.size(); j += 2){
      if((tmp.size() - j) == 1){
        arr[strLength / 2] = tmp[j];
        continue;
      }
      arr[start] = tmp[j];
      arr[end] = tmp[j+1];
      start++;
      end--;
    }
  }
  for(int i = 0; i < strLength; i++){
    cout << arr[i] + 1 << " ";
  }
  cout << endl;
  delete  [] arr;
}
*/
int main(){
  int t;
  cin >> t;

  while(t--){
    string str;
    cin >> str;
    palindromePrint(str);
  }
  return 0;
}
