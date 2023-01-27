/*
Q. Pair Star

Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".

Sample Input 1 :
hello

Sample Output 1:
hel*lo

Sample Input 2 :
aaaa

Sample Output 2 :
a*a*a*a

*/

#include<iostream>
using namespace std;


int length(char ch[]){
  int num = 0;
  for(int i = 0; ch[i] != '\0'; i++){
    num++;
  }
  return num;
}
void helper(char ch[], int size){
  if(size == 0){
    return;
  }
  helper(ch+1,size-1);
  if(ch[0] == ch[1]){
    int n = length(ch);
    for(int i = n; i > 1; i--){
      ch[i] = ch[i-1];
    }
    ch[1] = '*';
    ch[n+1] = '\0';
  }
}

void pairStar(char input[]){
  int len = length(input);
  helper(input,len);
}
int main(){
  char ch[100];
  cin >> ch;
  pairStar(ch);
  cout << ch << endl;
  return 0;
}
