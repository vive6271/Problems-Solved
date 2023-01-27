/*
Q. Print the following pattern

Pattern for N = 4

    1
   23
  345
 4567

Input Format :
N (Total no. of rows)

Output Format :
Pattern in N lines

Sample Input :
5

Sample Output :

    1
   23
  345
 4567
56789

*/

#include <iostream>
using namespace std;

int main() {
  int n;

  cout << "Enter value of N" << endl;
  cin >> n;

  int i = 1;
  while(i <= n) {
    int k = 1;
    while(k <= n - i) {
      cout << " ";
      k += 1;
    }
    int j = 1;
    int val = i;
    while(j <= i) {
      cout << val;
      val += 1;
      j += 1;
    }
    cout << endl;
    i += 1;
  }
}
