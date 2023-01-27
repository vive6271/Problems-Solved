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

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    if(input.empty()){
        output[0] = "";
        return 1;
    }
    string smallOutput1[500], smallOutput2[500];
    int smallCal1 = getCodes(input.substr(1), smallOutput1);
    int smallCal2 = 0, num = 0;
    if(input[1] != '\0'){
        num = (input[0] - '0') * 10 + (input[1] - '0');
        if(num <= 26 && num >= 10){
            smallCal2 = getCodes(input.substr(2), smallOutput2);
        }
    }
    int k = 0;
    num = (input[0] - '0');
    char ch = ('a' + num - 1);
    for(int i = 0; i < smallCal1; i++){
        output[k++] = ch + smallOutput1[i];
    }

    if(smallCal2 != 0){
        num = (input[0] - '0') * 10 + (input[1] - '0');
        ch = ('a' + num - 1);
        for(int i = 0; i < smallCal2; i++){
            output[k++] = ch + smallOutput2[i];
        }
    }
    return k++;
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
