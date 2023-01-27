/*
Q. Remove Duplicates Recursively

Given a string S, remove consecutive duplicates from it recursively.

Sample Input 1 :
aabccba

Sample Output 1 :
abcba

Sample Input 2 :
xxxyyyzwwzzz

Sample Output 2 :
xyzwz

*/

#include<iostream>
using namespace std;

void removeConsecutiveDuplicates(char *input){
  if(input[0] == '\0'){
    return;
  }
  removeConsecutiveDuplicates(input+1);
  if(input[0] == input[1]){
    int i = 2;
    for(; input[i] != '\0'; i++){
      input[i-1] = input[i];
    }
    input[i-1] = input[i];
  }
}

int main(){
  char ch[100];
  cin >> ch;
  removeConsecutiveDuplicates(ch);
  cout << ch << endl;
  return 0;
}
