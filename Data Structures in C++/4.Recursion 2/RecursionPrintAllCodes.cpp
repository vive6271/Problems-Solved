/*
Q. Print all Codes - String

Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. 
Write a program to print the list of all possible codes that can be generated from the given string.

Note : The order of codes are not important. Just print them in different lines.


Sample Input:
1123

Sample Output:
aabc
kbc
alc
aaw
kw
*/
#include<iostream>
using namespace std;

void printHelper(string input, string output){
  if(input.length() == 0){
    cout << output << endl;
    return;
  }
  int num = input[0] - '0';
  char ch = ('a' + num - 1);
  printHelper(input.substr(1), (output+ch));
  if(input[0] != '\0'){
    num = (input[0] - '0') * 10 + (input[1] - '0');
    ch = ('a' + num - 1);
    if(num >= 10 && num <= 26){
      printHelper(input.substr(2), (output+ch));
    }
  }
}

void printAllPossibleCodes(string input){
  printHelper(input,"");
}

int main(){
  string input;
  cin >> input;
  printAllPossibleCodes(input);
  return 0;
}
