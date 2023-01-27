/*
Q. Print Keypad Combinations Code

Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.

Note : The order of strings are not important. Just print different strings in new lines.

Sample Input:
23

Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

#include<iostream>
#include <string>
using namespace std;

string getString(int n){
  if(n == 2){
    return "abc";
  }else if(n == 3){
    return "def";
  }else if(n == 4){
    return "ghi";
  }else if(n == 5){
    return "jkl";
  }else if(n == 6){
    return "mno";
  }else if(n == 7){
    return "pqrs";
  }else if(n == 8){
    return "tuv";
  }else if(n == 9){
    return "wxyz";
  }
  return " ";
}

void helperString(int num, string output){
  if(num == 0){
    cout << output << endl;
    return;
  }
  int lastDigit = num%10;
  int smallNum = num/10;
  string str = getString(lastDigit);
  for(int i = 0; i < str.length(); i++){
    helperString(smallNum, str[i]+output);
  }
}
void printKeypad(int num){
  helperString(num,"");
}

int main(){
  int n;
  cin >> n;
  printKeypad(n);
  return 0;
}
