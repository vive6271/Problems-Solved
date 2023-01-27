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
using namespace std;

int power(int num){
  if(num == 0){
    return 1;
  }
  int smallCal = power(num-1);
  return 10 * smallCal;
}
int helper(char ch[], int size){
  if(size == 0){
    return ch[0] - '0';
  }
  int smallCalculation = helper(ch+1, size-1);
  int num = ch[0] - '0';
  return num * power(size) + smallCalculation;
}

int stringToNumber(char input[]){
  int len = 0;
  for(int i = 0; input[i] != '\0'; i++){
    len++;
  }
  int ans = helper(input, len-1);
  return ans;
}

int main(){
  char ch[100];
  cin >> ch;
  int output = stringToNumber(ch);
  cout << output << endl;
  return 0;
}
