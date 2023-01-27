/*
Q. String to Integer

Write a recursive function to convert a given string into the number it represents. 
That is input will be a numeric string that contains only numbers, you need to convert 
the string into corresponding integer and return the answer.

Sample Input 1 :
00001231

Sample Output 1 :
1231

Sample Input 2 :
12567

Sample Output 2 :
12567

*/

#include<iostream>
#include<cstring>
using namespace std;

int helper(char input[], int last){
    if(last == 0){
        return input[0] - '0';
    }
    int smallCal = helper(input, last-1);
    return 10 * smallCal + (input[last] - '0');
}

int stringToNumber(char input[]) {
    // Write your code here
    int len = strlen(input);
    return helper(input, len-1);
}

int main(){
  char ch[100];
  cin >> ch;
  int output = stringToNumber(ch);
  cout << output << endl;
  return 0;
}