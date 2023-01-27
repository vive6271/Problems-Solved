/*
Q. Check AB

Suppose you have a string, S, made up of only 'a's and 'b's. 
Write a recursive function that checks if the string was generated using the following rules:

a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'

If all the rules are followed by the given string, return true otherwise return false.

Sample Input 1 :
abb

Sample Output 1 :
true

Sample Input 2 :
abababa

Sample Output 2 :
false

Explanation for Sample Input 2
In the above example, a is not followed by either "a" or "bb", instead it's followed by "b" which results in false to be returned.
*/
#include<iostream>
using namespace std;

bool check(char input[]){
	if(input[0] == '\0'){
		return true;
	}
	int num = 1;
	if(input[0] == 'b'){
		if(input[1] == 'a'){
			return false;
		}
		num++;
	}
	check(input+num);
}

bool checkAB(char input[]) {
	// Write your code here
	if(input[0] != 'a'){
		return false;
	}
	return check(input);
}


int main(){
  char s[100];
  cin >> s;
  bool output = checkAB(s);
  if(output){
    cout << "True" << endl;
  }else{
    cout << "False" << endl;
  }
}
