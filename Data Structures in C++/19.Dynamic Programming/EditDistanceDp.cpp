/*
Q. Edit Distance (DP)

You are given two strings S and T of lengths M and N, respectively. Find the 'Edit Distance' between the strings.
Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. 

In order to do so, you can perform the following three operations:
1. Delete a character
2. Replace a character with another one
3. Insert a character

Sample Input 1 :
abc
dc

Sample Output 1 :
2

Explanation to the Sample Input 1 :

In 2 operations we can make string T to look like string S.
First, insert character 'a' to string T, which makes it "adc".

And secondly, replace the character 'd' of string T with 'b' from the string S. 
This would make string T as "abc" which is also string S. Hence, the minimum distance.

Sample Input 2 :
whgtdwhgtdg
aswcfg

Sample Output 2 :
9
*/

#include <iostream>
#include <string>
using namespace std;

int editDistance(string s1, string s2){
  int m = s1.size(), n = s2.size();
  int **output = new int*[m+1];
  for(int i = 0; i <= m; i++){
    output[i] = new int[n+1];
  }
  //Fill 1st row
  for(int j = 0; j <= n; j++){
    output[0][j] = j;
  }
  //Fill 1st col
  for(int i = 1; i <= m; i++){
    output[i][0] = i;
  }

  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){
      if(s1[m-i] == s2[n-j]){
        output[i][j] = output[i-1][j-1];
      }else{
        int x = output[i-1][j];
        int y = output[i][j-1];
        int z = output[i-1][j-1];
        output[i][j] = 1 + min(x, min(y,z));
      }
    }
  }
  return output[m][n];
}

int main(){
  string s1, s2;
  cin >> s1 >> s2;
  cout << editDistance(s1,s2) << endl;
  return 0;
}
