#include<iostream>
using namespace std;

void removeX(char s[]){
  if(s[0] == '\0'){
    return;
  }

  if(s[0] != 'x'){
    removeX(s+1);
  }else{
    int i = 1;
    for(; s[i] != '\0'; i++){
      s[i-1] = s[i];
    }
    s[i-1] = s[i];
    //-----Note :- Because we already reduced the length of string by 1 -----------------//
    removeX(s);
  }
}

int main(){
  char ch[100];
  cin >> ch;
  removeX(ch);
  cout << ch << endl;
  return 0;
}
