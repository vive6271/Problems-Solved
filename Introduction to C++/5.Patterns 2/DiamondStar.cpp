/*
Q. Diamond of stars

Print the following pattern for the given number of rows.

Note: N is always odd.

Pattern for N = 5
  *
 ***
*****
 ***
  *

Sample Input 1:
5

Sample Output 1:
  *
 ***
*****
 ***
  *

Sample Input 2:
3

Sample Output 2:
  *
 ***
  *

*/

#include<iostream>
using namespace std;

int main() {
  int n;

  cin >> n;

  int n1 = (n + 1) / 2;
  int n2 = n - n1;

  int i = 1;
  while(i <= n1){
    int space = 1;
    while(space <= n1 - i){
      cout << " ";
      space++;
    }
    int star = 1;
    while(star <= 2 * i - 1){
      cout << "*";
      star++;
    }
    cout << endl;
    i++;
  }

  int j = n2;
  while(j >= 1){
    int space2 = 1;
    while(space2 <= n2 - j + 1 ){
      cout << " ";
      space2++;
    }
    int star2 = 1;
    while(star2 <= 2 * j - 1){
      cout << "*";
      star2++;
    }
    cout << endl;
    j--;
  }
}
