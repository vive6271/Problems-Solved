/*
Q. Replace pi (recursive)

Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

Sample Input 1 :
xpix

Sample Output :
x3.14x

Sample Input 2 :
pipi

Sample Output :
3.143.14

Sample Input 3 :
pip

Sample Output :
3.14p

*/

#include<iostream>
using namespace std;

void helper(char ch[], int size){
  if(size == 0){
    return;
  }
  if(ch[0] == 'p' && ch[1] == 'i'){
    for(int i = size; i > 1; i--){
        ch[i+2] = ch[i];
    }
    ch[0] = '3', ch[1] = '.', ch[2] = '1', ch[3] = '4';
  }
  helper(ch+1, size-1);
}

void relpacePi(char ch[]){
  int len = 0;
  for(int i = 0; ch[i] != '\0'; i++){
    len++;
    if(ch[i] == 'p' && ch[i+1] == 'i'){
      len += 2;
    }
  }
  //----------------Because-We- also-considering---NULL('\0')-------------------//
  helper(ch, len);
}

int main(){
  char ch[100];
  cin >> ch;
  relpacePi(ch);
  cout << ch << endl;
  return 0;
}
