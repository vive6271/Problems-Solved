#include<iostream>
using namespace std;

void printSubSequence(string input, string output){
  if(input.length() == 0){
    cout << output << endl;
    return;
  }

  printSubSequence(input.substr(1), output);
  printSubSequence(input.substr(1), output + input[0]);
}

int main(){
  string input;
  cin >> input;
  string output = "";
  printSubSequence(input,output);
  return 0;
}
