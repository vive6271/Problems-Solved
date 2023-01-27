#include<iostream>
using namespace std;

int power(int n){
  if(n == 0){
    return 1;
  }
  return 2 * power(n-1);
}

int subSequence(string input, string output[]){
  if(input.empty()){
    output[0] = "";
    return 1;
  }

  string smallString = input.substr(1);
  int smallOutputSize = subSequence(smallString,output);
  for(int i = 0; i < smallOutputSize; i++){
    output[i+smallOutputSize] = input[0]+output[i];
  }
  return 2 * smallOutputSize;
}

int main(){
  string s;
  cin >> s;
  int strLength = s.size();
  string* output = new string[power(strLength)];
  int count = subSequence(s,output);
  for(int i = 0; i < count; i++){
    cout << output[i] << endl;
  }
  return 0;
}
