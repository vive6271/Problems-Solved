/*
Q. Replace pi (recursive)

Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

Sample Input 1 :
xpix

Sample Output :
x3.14x

Sample Input 2 :
pipi

Sample Output :
3.143.14

Sample Input 3 :
pip

Sample Output :
3.14p

*/

#include<iostream>
#include<cstring>
using namespace std;

void replacePi(char input[]) {
	// Write your code here
	if(input[0] == '\0'){
		return;
	}
	if(input[0] == 'p' && input[1] == 'i'){
		int len = strlen(input);
		for(int i = len+2; i >= 4; i--){
			input[i] = input[i-2];
		}
		input[0] = '3', input[1] = '.', input[2] = '1', input[3] = '4';
		replacePi(input+4);
	}else{
		replacePi(input+1);
	}
}

int main(){
  char ch[100];
  cin >> ch;
  replacePi(ch);
  cout << ch << endl;
  return 0;
}