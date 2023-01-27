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
#include<cstring>
using namespace std;

void pairStar(char input[]) {
    // Write your code here
    if(input[0] == '\0'){
        return;
    }
    if(input[0] == input[1]){
        int len = strlen(input);
        for(int i = len+1; i >= 2; i--){
            input[i] = input[i-1];
        }
        input[1] = '*';
        pairStar(input+2);
    }else{
        pairStar(input+1);
    }
}

int main(){
  char ch[100];
  cin >> ch;
  pairStar(ch);
  cout << ch << endl;
  return 0;
}