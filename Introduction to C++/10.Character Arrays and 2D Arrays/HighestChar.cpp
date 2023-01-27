/*
Q. Highest Occuring Character

For a given a string(str), find and return the highest occurring character.
Example:

Input String: "abcdeapapqarr"

Expected Output: 'a'
Since 'a' has appeared four times in the string which happens to be the highest frequency character, the answer would be 'a'.
If there are two characters in the input string with the same frequency, return the character which comes first.

Consider:
Assume all the characters in the given string to be in lowercase always.

Sample Input 1:
abdefgbabfba

Sample Output 1:
b

Sample Input 2:
xy

Sample Output 2:
x
*/

#include<iostream>
#include<climits>
using namespace std;

char highestChar(char input[]){
  int num = 0, o, p;
  for(int i = 0; input[i] != '\0'; i++){
    num++;
  }
  int Hz[256];
  for(int j = 0; j < 256; j++){
    Hz[j] = 0;
  }
  for(int k = 0; k < num; k++){
    o = input[k];
    p = Hz[o];
    p = p + 1;
    Hz[o] = p;
  }
  // Max //
  int max = INT_MIN;
  char maxChar;
  for(int l = 0; l < num; l++){
    o = input[l];
    p = Hz[o];
    if(max < p){
      max = p;
      maxChar = input[l];
    }
  }
  return maxChar;
}
/*
char highestOccurringChar(char input[]) {
    // Write your code here
    char ans;
    int maxCount = -1;
    int freq[256] = {0};
    for(int i = 0; input[i] != '\0'; i++){
        freq[input[i]]++;
    }
    for(int i = 0; i < 256; i++){
        if(maxCount < freq[i]){
            maxCount = freq[i];
            ans = i;
        }
    }
    return ans;
}
*/
int main(){
  char input[100];
  cin >> input;
  cout << highestChar(input) << endl;
}
