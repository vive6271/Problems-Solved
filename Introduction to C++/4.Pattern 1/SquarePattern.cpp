/*
Q. Square Pattern

Print the following pattern for the given N number of rows.

Pattern for N = 4
4444
4444
4444
4444

Sample Input 1:
7

Sample Output 1:
7777777
7777777
7777777
7777777
7777777
7777777
7777777

Sample Input 1:
6

Sample Output 1:
666666
666666
666666
666666
666666
666666
*/


#include<iostream>
using namespace std;

int main() {
  int n;

  cout << " Enter value of N " << endl;
  cin >> n;

  int i = 1;
  while(i <= n) {
    int j = 1;
    while(j <= n) {
      cout << n ;
      j++;
    }
    cout << endl;
    i++;
  }
}
