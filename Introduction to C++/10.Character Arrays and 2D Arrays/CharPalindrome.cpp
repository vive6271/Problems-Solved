/*
Q. Check Palindrome

Given a string, determine if it is a palindrome, considering only alphanumeric characters.

Palindrome
A palindrome is a word, number, phrase, or other sequences of characters which read the same backwards and forwards.

Example:
If the input string happens to be, "malayalam" then as we see that this word can be read the same as forward and backwards, it is said to be a valid palindrome.

The expected output for this example will print, 'true'.

Sample Input 1 :
abcdcba

Sample Output 1 :
true 

Sample Input 2:
coding

Sample Output 2:
false
*/

#include<iostream>
using namespace std;

/*
bool checkPalindrome(char arr[]) {
  // Write your code here
  int count = 0;
  for(int i = 0; arr[i] != '\0'; i++){
    count++;
  }
  int i = 0, j = count-1;
  while(i < j){
    if(arr[i] != arr[j]){
      return false;
    }
    i++;
    j--;
  }
  return true;
}
*/

bool charPalindrome(char arr[]){
  bool isPalindrome;
  int n = 0;
  for(int i = 0; arr[i] != '\0'; i++){
    n++;
  }
  int num = (n / 2) + 1;
  for(int j = 0; j < num; j++){
    if(arr[j] == arr[n-j-1]){
      isPalindrome = true;
    }else{
      isPalindrome = false;
    }
  }
  return isPalindrome;
}

int main(){
  char name[100];
  cin >> name;

  string isTrue;
  int x = charPalindrome(name); // bool return true or false in the form of 1 or 0 | So that we are saving it into "int" //
  if(x == 1){
    isTrue = "True";
  }else{
    isTrue = "False";
  }
  cout << isTrue << endl;
}
