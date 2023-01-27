/*
Q. Replace Character

Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.

Sample Input :
abacd
a x

Sample Output :
xbxcd
*/

#include<iostream>
using namespace std;

void replaceChar(char arr[], char c1, char c2){
  for(int i = 0; arr[i] != '\0'; i++){
    if(arr[i] == c1){
      arr[i] = c2;
    }
  }
}

int main() {
  char name[100];
  cin >> name;

  char c1 , c2;
  cin >> c1 >> c2;

  replaceChar( name, c1, c2);
  cout << name << endl;
}
