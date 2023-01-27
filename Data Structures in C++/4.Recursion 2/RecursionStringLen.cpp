#include<iostream>
using namespace std;

int stringLength(char s[]){
  if(s[0] == '\0'){
    return 0;
  }
  int smallCalculation = stringLength(s+1);
  return smallCalculation+1;
}

int main(){
  char ch[100];
  cin >> ch;
  int output = stringLength(ch);
  cout << output << endl;
  return 0;
}
