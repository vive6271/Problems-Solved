/*
Q. Compress the String

Write a program to do basic string compression. For a character which is consecutively repeated more than once, replace consecutive duplicate occurrences with the count of repetitions.

Example:
If a string has 'x' repeated 5 times, replace this "xxxxx" with "x5".

The string is compressed only when the repeated character count is more than 1.

Note:
Consecutive count of every character in the input string is less than or equal to 9.

Sample Input 1:
aaabbccdsa

Sample Output 1:
a3b2c2dsa

Explanation for Sample Output 1:
In the given string 'a' is repeated 3 times, 'b' is repeated 2 times, 'c' is repeated 2 times and 'd', 's' and 'a' and occuring 1 time hence no compression for last 3 characters.

Sample Input 2:
aaabbcddeeeee

Sample Output 2:
a3b2cd2e5

Explanation for Sample Output 2:
In the given string 'a' is repeated 3 times, 'b' is repeated 2 times, 'c' is occuring single time, 'd' is repeating 2 times and 'e' is repeating 5times.
*/

#include<iostream>
using namespace std;

 string getCompressedString(string &input) {
    // Write your code here.
    int len = input.length();
    string str = "";
    if(len == 0){
        return str;
    }
    int i = 0;
    while(i < len){
        int sameWord = 1;
        str += input[i];
        int j = i;
        while(input[j] == input[j+1] && (j+1) < len){
            sameWord++;
            j++;
        }
        if(sameWord > 1){
        str += (char) ('0' + sameWord);
        }
        i += sameWord;
    }
    return str;
}

int main(){
  string input;
  cin >> input;
  getCompressedString(input);
  cout << input << endl;
  return 0;
}
