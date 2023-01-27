/*
Q. Character Pattern

Print the following pattern for the given N number of rows.

Pattern for N = 4
A
BC
CDE
DEFG

Sample Input 1:
5

Sample Output 1:
A
BC
CDE
DEFG
EFGHI

Sample Input 2:
6

Sample Output 2:
A
BC
CDE
DEFG
EFGHI
FGHIJK

*/

#include<iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int i = 1;
  while(i <= n){
    int j = 1;
    int k = i;
    while(j <= i){
      char ch = 'A' + k - 1;
      cout << ch;
      k++;
      j++;
    }
    cout << endl;
    i++;
  }
}
