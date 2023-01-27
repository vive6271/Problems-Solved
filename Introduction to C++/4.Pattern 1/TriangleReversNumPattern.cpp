/*
Q. Reverse Number Pattern

Print the following pattern for the given N number of rows.

Pattern for N = 4
1
21
321
4321

Sample Input 1:
5

Sample Output 1:
1
21
321
4321
54321

Sample Input 2:
6

Sample Output 2:
1
21
321
4321
54321
654321
*/
#include<iostream>
using namespace std;

int main() {
  int n ;
  cin >> n;
  int i = 1;
  while(i <= n){
    int j = i;
    while(j >= 1){
      cout << j;
      j--;
    }
    cout << endl;
    i++;
  }
}
