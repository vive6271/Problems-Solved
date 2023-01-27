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
#include<cstring>

void removeX(char input[]) {
    // Write your code here
    if(input[0] == '\0'){
        return;
    }
    if(input[0] == 'x'){
        int len = strlen(input);
        for(int i = 0; i < len; i++){
            input[i] = input[i+1];
        }
        removeX(input);
    }else{
      removeX(input + 1);
    }
}

int main(){
  char ch[100];
  cin >> ch;
  removeX(ch);
  cout << ch << endl;
  return 0;
}