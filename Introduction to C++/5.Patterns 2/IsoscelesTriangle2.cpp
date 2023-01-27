/*
Q. Triangle of Numbers

Print the following pattern for the given number of rows.

Pattern for N = 4
   1
  232
 34543
4567654

Sample Input 1:
5

Sample Output 1:
    1
   232
  34543
 4567654
567898765

Sample Input 2:
4

Sample Output 2:
   1
  232
 34543
4567654
*/
#include<iostream>
using namespace std;

int main(){
  int n;

  cin >> n;

  int i = 1;
  while(i <= n){
    int space = 1;
    while(space <= n - i){
      cout << " ";
      space++;
    }
    int num = 1;
    int j = i;
    while(num <= i) {
      cout << j;
      j++;
      num++;
    }
    int num2 = i - 1;
    int k = i + num2 - 1;
    while(num2 >= 1){
      cout << k;
      k--;
      num2--;
    }

    cout << endl;
    i++;
  }
}
