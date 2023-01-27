/*
Q. Mirror Number Pattern

Print the following pattern for the given N number of rows.

Pattern for N = 4
   1 
  12
 123
1234

Sample Input 1:
3

Sample Output 1:
    1 
   12
  123

Sample Input 2:
4

Sample Output 2:
   1 
  12
 123
1234
*/

#include<iostream>
using namespace std;

int main() {
  int n;

  cin >> n;

  int i = 1;
  while(i <= n) {
    int space = 1;
    while(space <= n - i){
      cout << " " ;
      space++;
    }
    int star = 1;
    while(star <= i){
      cout << "*";
      star++;
    }
    cout << endl;
    i++;
  }
}
