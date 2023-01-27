
/*
Q.Reverse Each Word

Aadil has been provided with a sentence in the form of a string as a function parameter. The task is to implement a function so as to print the sentence such that each word in the sentence is reversed.

Example:
Input Sentence: "Hello, I am Aadil!"
The expected output will print, ",olleH I ma !lidaA"

Sample Input 1:
Welcome to Coding Ninjas

Sample Output 1:
emocleW ot gnidoC sajniN

Sample Input 2:
Always indent your code

Sample Output 2:
syawlA tnedni ruoy edoc
*/
#include<iostream>
using namespace std;

void reverseChar(char arr[]){
  int num = 0;
  for(int i = 0; arr[i] != '\0'; i++){
    num++;
  }
  char swap;
  int count = 0;
  while(count < num){
    int space = 0;
    int word = 0;
    for(int j = count; arr[j] != '\0'; j++){
      if(arr[j] == ' '){
        space++;
        break;
      }else{
        word++;
      }
    }
    int endWord = count + word - 1;
    int startWord = count;
    while(startWord < endWord){
      swap = arr[startWord];
      arr[startWord] = arr[endWord];
      arr[endWord] = swap;
      startWord++;
      endWord--;
    }
    count = count + word + space;
  }
}

int main(){
  char input[100];
  cin.getline(input,100);
  reverseChar(input);
  cout << input << endl;
  return 0;
}
