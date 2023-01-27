/*
Q. Star Pattern

Print the following pattern

Pattern for N = 4
    *
   *** 
  *****
 *******

Sample Input 1 :
3

Sample Output 1 :
   *
  *** 
 *****

Sample Input 2 :
4

Sample Output 2 :
    *
   *** 
  *****
 *******
*/

#include<iostream>
using namespace std;

int main() {
  int n;

  cin >> n;

  int i = 1;
  while(i <= n){
    int space = 1;
    while(space <= n - i){
      cout << " ";
      space++;
    }
    int star = 1;
    while(star <= i){
      cout << "*";
      star++;
    }
    int star2 = i - 1;
    while(star2 >= 1){
      cout << "*";
      star2--;
    }
    cout << endl;
    i++;
  }
}
