/*
Q. Trim Spaces

Given an input string S that contains multiple words, you need to remove all the spaces present in the input string.
There can be multiple spaces present after any wor

Sample Input :
abc def g hi

Sample Output :
abcdefghi
*/

#include<iostream>
using namespace std;

void trimSpaces(char input[]){
  int j = 0;
  for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] != ' ') {
      input[j] = input[i];
      j++;
    }
  }
  input[j] = '\0';
}

int main() {
  char input[100];
  cin.getline(input,100);
  trimSpaces(input);
  cout << input << endl;
}
