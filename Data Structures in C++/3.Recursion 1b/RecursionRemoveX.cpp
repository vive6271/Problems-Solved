/*
Q. Remove X

Given a string, compute recursively a new string where all 'x' chars have been removed.
 
Sample Input 1 :
xaxb

Sample Output 1:
ab

Sample Input 2 :
abc

Sample Output 2:
abc

Sample Input 3 :
xx

Sample Output 3:
(No Output)
*/

#include<iostream>
using namespace std;

void helper(char ch[], int size){
  if(size == 0){
    return;
  }
  helper(ch+1, size-1);
  if(ch[0] == 'x'){
    for(int i = 0; ch[i] != '\0'; i++){
      ch[i] = ch[i+1];
    }
  }
}

void replaceX(char input[]){
  int len = 0;
  for(int i = 0; input[i] != '\0'; i++){
    len++;
  }
  helper(input, len);
}

int main(){
  char ch[100];
  cin >> ch;
  replaceX(ch);
  cout << ch << endl;
  return 0;
}
