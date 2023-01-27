/*
Q. Triangular Star Pattern

Print the following pattern for the given N number of rows.

Pattern for N = 4
*
**
***
****

Sample Input 1:
5

Sample Output 1:
*
**
***
****
*****

Sample Input 2:
6

Sample Output 2:
*
**
***
****
*****
******
*/

#include<iostream>
using namespace std;

int main() {
  int n;

  cout << "Enter value of N " << endl;
  cin >> n ;

  int i = 1;
  while (i <= n) {
    int j = 1;
    while (j <= i) {
      cout << "*";
      j++;
    }
    cout << endl;
    i++;
  }
}
