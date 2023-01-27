/*
Q. Replace Character Recursively

Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.
Do this recursively.

Sample Input :
abacd
a x

Sample Output :
xbxcd
*/

#include<iostream>
using namespace std;

void replaceChar(char input[], char c1, char c2){
  if(input[0] == '\0'){
    return;
  }
  replaceChar(input+1,c1,c2);
  if(input[0] == c1){
    input[0] = c2;
  }
}

int main(){
  char ch[100], c1, c2;
  cin >> ch;
  cin >> c1 >> c2;
  replaceChar(ch,c1,c2);
  cout << ch << endl;
  return 0;
}
