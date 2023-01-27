/*
Q. Check Permutation

For a given two strings, 'str1' and 'str2', check whether they are a permutation of each other or not.

Permutations of each other:
Two strings are said to be a permutation of each other when either of the string's characters can be rearranged so that it becomes identical to the other one.

Example: 
str1= "sinrtg" 
str2 = "string"

The character of the first string(str1) can be rearranged to form str2 and hence we can say that the given strings are a permutation of each other.

Sample Input 1:
abcde
baedc

Sample Output 1:
true

Sample Input 2:
abc
cbd

Sample Output 2:
false
*/

#include<iostream>
using namespace std;

int arrayLength(char arr[]){
  int num = 0;
  for(int i = 0; arr[i] != '\0'; i++){
    num++;
  }
  return num;
}
bool checkPermutation(char input1[], char input2[]){
  bool isSame = true;
  int num[256];
  for(int k = 0; k < 256; k++){
    num[k] = 0;
  }
  int n = arrayLength(input1);
  int m = arrayLength(input2);
  if(n == m){
    int o, p;
    for(int a = 0; a < n; a++){
      o = input1[a];
      p = num[o];
      p = p+1;
      num[o] = p;
    }
    for(int b = 0; b < m; b++){
      o = input2[b];
      p = num[o];
      p = p-1;
      num[o] = p;
    }
    for(int c = 0; c < 256; c++){
      if(num[c] != 0){
        isSame = false;
      }
    }
  }else{
    isSame = false;
  }
  return isSame;
}
/*
bool isPermutation(char input1[], char input2[]) {
    // Write your code here
    if(strlen(input1) != strlen(input2)){
        return false;
    }
    int freq[256] = {0};
    for(int i = 0; input1[i] != '\0'; i++){
        freq[input1[i]]++;
    }
    for(int i = 0; input2[i] != '\0'; i++){
        freq[input2[i]]--;
    }
    for(int i = 0; i < 256; i++){
        if(freq[i] != 0){
            return false;
        }
    }
    return true;
}
*/
int main(){
  char arr1[100], arr2[100];
  cin >> arr1 >> arr2;
  cout << checkPermutation(arr1, arr2) << endl;

  return 0;
}
