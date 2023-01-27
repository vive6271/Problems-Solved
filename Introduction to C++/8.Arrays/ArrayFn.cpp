#include<iostream>
using namespace std;

void Function(int input[]){
  cout << "Function : " << sizeof(input) << endl;
}

int main(){

  int input[10];

  cout << "Input : " << input << endl;
  cout << "Main : " << sizeof(input) << endl;
  Function(input);
}
