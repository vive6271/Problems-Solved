/*
Q. Print Permutations

Given an input string (STR), print all possible permutations of the input string.

Note:
The input string may contain the same characters, so there will also be the same permutations.
The order of permutations doesn’t matter.

Input Format:
The only input line contains a string (STR) of alphabets in lower case

Output Format:
Print each permutations in a new line

Sample Input 1:
cba

Sample Output 1:
abc
acb
bac
bca
cab
cba
*/
#include<iostream>
using namespace std;

void printHelper(string input, string output){
  if(input.length() == 0){
    cout << output << endl;
    return;
  }
  for(int i = 0; i <= output.length(); i++){
    printHelper(input.substr(1), (output.substr(0,i) + input[0] + output.substr(i)));
  }
}

void printPermutation(string input){
  printHelper(input,"");
}

int main(){
  string input;
  cin >> input;
  printPermutation(input);
  return 0;
}
