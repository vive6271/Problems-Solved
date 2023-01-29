#include <iostream>
#include<cstring>
#include<map>
using namespace std;

int main() {
    // Write your code here
    string str;
    getline(cin,str);
    map<string,int> Map;
    for(int i = 0; i < str.length(); ){
      int j;
      string s;
      for(j = i; j < str.length(); j++){
        if(str[j] == ' '){
          j++;
          break;
        }
        s += str[j];
      }
      i = j;
      Map[s]++;
    }
    bool sameFound = false;
    map<string,int> :: iterator it;
    for(it = Map.begin(); it != Map.end(); it++){
      if(it -> second > 1){
        cout << it -> first << " " << it -> second << endl;
        sameFound = true;
      }
    }
    if(!sameFound){
      cout << "-1" << endl;
    }
    return 0;
}
