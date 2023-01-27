/* 
Q. Return all codes - String

Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. 
Write a program to return the list of all possible codes that can be generated from the given string.

Note : The order of codes are not important. And input string does not contain 0s.

Sample Input:
1123

Sample Output:
aabc
kbc
alc
aaw
kw
*/

#include<iostream>
using namespace std;

int getCodes(string input, string output[]){
  if(input.length() == 0){
    output[0] = "";
    return 1;
  }
  string NewOutput1[500], NewOutput2[500];
  int smallCal1 = getCodes(input.substr(1),NewOutput1);
  int smallCal2 = 0;
  if(input[1] != '\0'){
    smallCal2 = getCodes(input.substr(2),NewOutput2);
    }
    int k = 0;
    int num = input[0] - '0';
    char ch = ('a'+ num - 1);
    for(int i = 0; i < smallCal1; i++){
      output[k] = ch + NewOutput1[i];
      k++;
    }

    if(( input[0] == '2' && input[1] <= '6') || (input[0] == '1' && input[1] <= '9')){
      int num = (input[0]-'0')*10+(input[1]-'0');
      char ch = ('a'+num-1);
      for(int i = 0; i < smallCal2; i++){
        output[k] = ch + NewOutput2[i];
        k++;
      }
  }
  return k;
}

int main(){
  string input;
  cin >> input;

  string output[10000];
  int count = getCodes(input,output);
  for(int i = 0; i < count && i < 1000; i++){
    cout << output[i] << endl;
  }
  return 0;
}
