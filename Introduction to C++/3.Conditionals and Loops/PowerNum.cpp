/*
Q. Find power of a number

Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to print the answer.

Note : For this question, you can assume that 0 raised to the power of 0 is 1


Sample Input 1 :
3 4

Sample Output 1 :
81

Sample Input 2 :
2 5

Sample Output 2 :
32

*/

#include <iostream>
using namespace std;

int main() {
  int num;
  int power;

  cout << "Enter value of Number and Power " << endl;
  cin >> num >> power;

  int i = 1;
  int square = 1;
  while(i <= power) {
    square = square * num;
    i += 1;
  }
  cout << square << endl;
}
