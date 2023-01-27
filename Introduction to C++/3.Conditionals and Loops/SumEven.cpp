/*
Q. Sum of Even Numbers till N

Given a number N, print sum of all even numbers from 1 to N.

Sample Input 1 :
 6

Sample Output 1 :
12
*/
#include <iostream>
using namespace std;

int main() {
  int n;
  std::cin >> n;

  int d = 1;
  int sum = 0;

  while (d <= n) {
    if (d % 2 == 0) {
      sum = sum + d;
    }
    d = d + 1;
  }
  cout << sum << endl;
}
