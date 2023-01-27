/*
Q. Terms of AP

Write a program to print first x terms of the series 3N + 2 which are not multiples of 4.

Sample Input 1 :
10

Sample Output 1 :
5 11 14 17 23 26 29 35 38 41

Sample Input 2 :
4

Sample Output 2 :
5 11 14 17

*/

#include<iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int count = 1;
  int m = 1;
  int terms = 0;
  while(count <= n){
    terms = (3 * m) + 2;
    if(terms % 4 != 0){
      cout << terms << " ";
      count++;
    }
    m++;
  }
  cout << endl;
}
