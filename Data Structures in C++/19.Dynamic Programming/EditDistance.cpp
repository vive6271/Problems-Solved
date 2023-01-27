/*
Q. Edit Distance (Brute Force)

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
  if(s1.size() == 0 || s2.size() == 0){
    return max(s1.size(),s2.size());
  }
  if(s1[0] == s2[0]){
    return editDistance(s1.substr(1), s2.substr(1));
  }else{
    int x = editDistance(s1.substr(1), s2); // Insert
    int y = editDistance(s1, s2.substr(1)); // Delete
    int z = editDistance(s1.substr(1), s2.substr(1)); // Replace
    return 1 + min(x,min(y,z));
  }
}

int main(){
  string s1, s2;
  cin >> s1 >> s2;
  cout << editDistance(s1,s2) << endl;
  return 0;
}
