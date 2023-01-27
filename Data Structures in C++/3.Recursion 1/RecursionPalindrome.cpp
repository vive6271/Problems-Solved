/*
Q. Check Palindrome (recursive)

Check whether a given String S is a palindrome using recursion. Return true or false.

Sample Input 1 :
racecar

Sample Output 1:
true

Sample Input 2 :
ninja

Sample Output 2:
false

*/
#include<iostream>
using namespace std;

bool helper(char *s, int start, int end){
  if(start > end){
    return true;
  }
  if(s[start] != s[end]){
    return false;
  }
  bool smallCalculation = helper(s, start+1, end-1);
  return smallCalculation;
}

bool checkPalindrome(char input[]){
  int len = 0;
  for(int i = 0; input[i] != '\0'; i++){
    len++;
  }
  bool isPalindrome = helper(input, 0, len-1);
  return isPalindrome;
}

int main(){
  char ch[100];
  cin >> ch;

  bool isTrue = checkPalindrome(ch);

  if(isTrue){
    cout << "True" << endl;
  }else{
    cout << "False" << endl;
  }
  return 0;
}
