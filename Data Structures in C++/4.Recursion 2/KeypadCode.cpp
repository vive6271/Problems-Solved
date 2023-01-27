/*
Q. Return Keypad Code

Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.

Note : 
1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array 
and return the count of elements populated in the output array.

Sample Input:
23

Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf

*/

#include<iostream>
using namespace std;

int arrSpace(int n){
  if(n == 0){
    return 1;
  }
  int smallNum = arrSpace(n/10);
  if(n%10 == 7 || n%10 == 9){
    return 4 * smallNum;
  }else if(n%10 == 0 || n%10 == 1){
    return smallNum;
  }
  return 3 * smallNum;
}
string getString(int n){
  if(n == 2){
    return "abc";
  }else if(n == 3){
    return "def";
  }else if(n == 4){
    return "ghi";
  }else if(n == 5){
    return "jkl";
  }else if(n == 6){
    return "mno";
  }else if(n == 7){
    return "pqrs";
  }else if(n == 8){
    return "tuv";
  }else if(n == 9){
    return "wxyz";
  }
  return " ";
}
int keypad(int num, string output[]){
  if(num == 0){
    output[0] = "";
    return 1;
  }
  int lastDigit = num%10;
  int smallNum = num/10;
  int smallCal = keypad(smallNum, output);

  string str = getString(lastDigit);

  for(int i = 0; i < str.length()-1; i++){
    for(int j = 0; j < smallCal; j++){
      output[j+(i+1) * smallCal] = output[j];
    }
  }

  int k = 0;
  for(int i = 0; i < str.length(); i++){
    for(int j = 0; j < smallCal; j++){
      output[k] = output[k] + str[i];
      k++;
    }
  }
  return smallCal * str.length();
}

int main(){
  int n;
  cin >> n;

  string* output = new string[arrSpace(n)];
  int count = keypad(n,output);
  for(int i = 0; i < count; i++){
    cout << output[i] << endl;
  }
  return 0;
}
