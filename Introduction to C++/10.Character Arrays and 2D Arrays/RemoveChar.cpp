/*
Q. Remove character

For a given a string(str) and a character X, write a function to remove all the occurrences of X from the given string.
The input string will remain unchanged if the given character(X) doesn't exist in the input string.

Sample Input 1:
aabccbaa
a

Sample Output 1:
bccb

Sample Input 2:
xxyyzxx
y

Sample Output 2:
xxzxx
*/

#include<iostream>
using namespace std;

void removeChar(char input[], char c){
  int j = 0;
  for(int i = 0; input[i] != '\0'; i++){
    if(input[i] != c){
      input[j] = input[i];
      j++;
    }
  }
  input[j] = '\0';
}

int main(){
  char input1[100], input2;
  cin.getline(input1, 100);
  cin >> input2;
  removeChar(input1, input2);
  cout << input1 << endl;
  return 0;
}
