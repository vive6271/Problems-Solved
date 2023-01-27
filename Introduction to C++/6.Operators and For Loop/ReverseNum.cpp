/*
Q. Reverse of a number

Write a program to generate the reverse of a given number N. Print the corresponding reverse number.

Note : If a number has trailing zeros, then its reverse will not include them. For e.g., reverse of 10400 will be 401 instead of 00401.


Sample Input 1 :
1234

Sample Output 1 :
4321

Sample Input 2 :
1980

Sample Output 2 :
891
*/

#include<iostream>
using namespace std;

int main() {
  int n ;
  cin >> n;

  int reminder = 0;
  int div = n;
  int rev = 0;
  while(div > 0){
    reminder = div % 10;
    div = div / 10;

    rev = rev * 10 + reminder;
  }
  cout << rev << endl;
}
