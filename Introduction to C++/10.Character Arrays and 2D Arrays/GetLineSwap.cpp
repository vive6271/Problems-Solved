#include<iostream>
using namespace std;

int length(char input[]){
  int count = 0;
  for(int i = 0; input[i] != '\0'; i++){
    count++;
  }
  return count;
}

void reverseChar(char input[]){
  int arrLength = length(input);
  int a = 0;
  int b = arrLength - 1;
  char swap;
  while(a < b){
    swap = input[a];
    input[a] = input[b];
    input[b] = swap;
    a++;
    b--;
  }
}

int main() {
  char input[100];
  cin.getline(input, 100);

  reverseChar(input);

  cout << input << endl;
}
