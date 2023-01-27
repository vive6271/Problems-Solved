/*
Q.Reverse Word Wise

Reverse the given string word wise. That is, the last word in given string should come at 1st place, last second word at 2nd place and so on. Individual words should remain as it is.

Sample Input 1:
Hello World

Sample Output 1:
World Hello

Sample Input 2:
Always indent your code

Sample Output 2:
code your indent Always
*/

#include<iostream>
using namespace std;

void reverseWord(char input[]){
  int count = 0; 
    for(int i = 0; input[i] != '\0'; i++){
        count++;
    }
    int start = 0, end = count-1;
    char swapChar;
    while(start < end){
        swapChar = input[start];
        input[start] = input[end];
        input[end] = swapChar;
        start++;
        end--;
    }
    
    int num = 0;
    while(num < count){
        int wordCount = 0, spaceCount = 0;
        for(int i = num; input[i] != '\0'; i++){
            if(input[i] == ' '){
                spaceCount++;
                break;
            }else{
                wordCount++;
            }
        }
        start = num, end = num+wordCount-1;
        while(start < end){
            swapChar = input[start];
            input[start] = input[end];
            input[end] = swapChar;
            start++;
            end--;
        }
        num = num + wordCount + spaceCount;
    }
}

int main() {
  char input[100];
  cin.getline(input,100);
  reverseWord(input);
  cout << input << endl;
}
