/*
Q. Print the following pattern

Pattern for N = 4

   *
  ***
 *****
*******

Input Format :
N (Total no. of rows)
Output Format :
Pattern in N lines


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

  cout << "Enter value of N" << endl;
  cin >> n;

  int i = 1;
  while(i <= n) {
    int j = 1;
    while(j <= n - i){
      cout << " " ;
      j += 1;
    }

    int k = 1;
    while(k <= 2*i - 1){
      cout << "*";
      k += 1;
    }
    cout << endl;
    i += 1;
  }
}
