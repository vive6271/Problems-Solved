/*
Q. Number Pattern 1

Print the following pattern

Pattern for N = 4

1
23
345
4567

Input Format :
N (Total no. of rows)

Output Format :
Pattern in N lines

Sample Input 1 :
3

Sample Output 1 :
1
23
345

*/

#include <iostream>
using namespace std;

int main() {
  int n ;

  cout << "Enter value of N" << endl;
  cin >> n;

  int i = 1;

  while(i <= n) {
    int j = 1, val = i;
    while(j <= i) {
      cout << val;
      val += 1;
      j += 1;
    }
    cout << endl;
    i += 1;
  }
}
