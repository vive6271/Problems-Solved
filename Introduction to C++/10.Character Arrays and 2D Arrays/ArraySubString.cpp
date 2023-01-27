/*
Q. Print All Substrings

For a given input string(str), write a function to print all the possible substrings.

Substring
A substring is a contiguous sequence of characters within a string. 
Example: "cod" is a substring of "coding". Whereas, "cdng" is not as the characters taken are not contiguous

Sample Input 1:
abc

Sample Output 1:
a 
ab 
abc 
b 
bc 
c 

Sample Input 2:
co

Sample Output 2:
c 
co 
o
*/

#include<iostream>
using namespace std;

void subString(char arr[]){
  int num = 0;
  while(arr[num] != '\0'){
    for(int i = num; arr[i] != '\0'; i++){
      for(int j = num; j <= i; j++){
        cout << arr[j];
      }
      cout << endl;
    }
    num++;
  }
}

int main(){
  char input[100];
  cin.getline( input, 100);

  subString(input);
}
