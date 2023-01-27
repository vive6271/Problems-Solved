/*
Q. Remove Consecutive Duplicates

For a given string(str), remove all the consecutive duplicate characters.

Example:
Input String: "aaaa"
Expected Output: "a"

Input String: "aabbbcc"
Expected Output: "abc"

Sample Input 1:
aabccbaa

Sample Output 1:
abcba

Sample Input 2:
xxyyzxx

Sample Output 2:
xyzx
*/

#include<iostream>
using namespace std;

void removeConsecutiveDuplicates(char input[]){
  int num = 0;
  for(int i = 0; input[i] != '\0'; i++){
    num++;
  }
  int k = 0;
  for(int j = 1; j <= num; j++){
    if(input[k] == input[j]){
      continue;
    }else{
      k++;
      input[k] = input[j];
    }
  }
}
/*
void removeConsecutiveDuplicates(char input[]) {
    // Write your code here
    int j = 0;
    for(int i = 1; input[i] != '\0'; i++){
      if(input[j] != input[i]){
        input[++j] = input[i];
      }
    }
    input[j+1] = '\0';
}
*/
int main() {
  char arr[100];
  cin >> arr;
  removeConsecutiveDuplicates(arr);
  cout << arr << endl;
  return 0;
}
