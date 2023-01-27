/*
Q. Minimum bracket Reversal

For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced. 
The expression will only contain curly brackets.If the expression can't be balanced, return -1.

Example:
Expression: {{{{
If we reverse the second and the fourth opening brackets, the whole expression will get balanced. Since we have to reverse two brackets to make the expression balanced, the expected output will be 2.

Expression: {{{
In this example, even if we reverse the last opening bracket, we would be left with the first opening bracket and hence will not be able to make the expression balanced and the output will be -1.

Input Format :
The first and the only line of input contains a string expression, without any spaces in between.

Output Format :
The only line of output will print the number of reversals required to balance the whole expression. Prints -1, otherwise.

Note:
You don't have to print anything. It has already been taken care of.

Sample Input 1:
{{{

Sample Output 1:
-1

Sample Input 2:
{{{{}}

Sample Output 2:
1
*/

#include <iostream>
#include <string>
using namespace std;

#include<stack>
int countBracketReversals(string input) {
	// Write your code here
  if(input.size() % 2 == 1){
    return -1;
  }
  stack<int> s;
  for(int i = 0; input[i] != '\0'; i++){
    if(input[i] == '{'){
      s.push(input[i]);
    }else if(input[i] == '}'){
      if(!s.empty() && s.top() == '{'){
        s.pop();
      }else{
        s.push(input[i]);
      }
    }
  }
  int count = 0;
  while(!s.empty()){
    char c1 = s.top();
    s.pop();
    char c2 = s.top();
    s.pop();
    if(c1 == c2){
      count++;
    }else{
      count += 2;
    }
  }
  return count;
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}
