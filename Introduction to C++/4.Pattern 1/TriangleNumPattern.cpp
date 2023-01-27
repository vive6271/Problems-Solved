/*
Q.Triangle Number Pattern

Print the following pattern for the given N number of rows.

Pattern for N = 4
1
22
333
4444

Sample Input 1:
5

Sample Output 1:
1
22
333
4444
55555

Sample Input 2:
6

Sample Output 2:
1
22
333
4444
55555
666666
*/

#include<iostream>
using namespace std;

int main() {
  int n, num;

  cout << "Enter value of N " << endl;
  cin >> n;

  for(int i = 1; i <= n; i++){
    num = i;
    for(int j = 1; j <= i; j++){
      cout << num;
    }
    cout << endl;
  }
}
