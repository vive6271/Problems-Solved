/*
Q. Decimal to Binary

Given a decimal number (integer N), convert it into binary and print.
The binary number should be in the form of an integer.

Sample Input 1 :
12

Sample Output 1 :
1100

Sample Input 2 :
7
*/

#include<iostream>
using namespace std;

int main(){
/*int num;
  cin >> num;

  int bin = 0;
  int PV = 1;
  int reminder = 0;
  while(num > 0){
    reminder = num % 2;
    bin += (PV * reminder);
    PV *= 10;
    num = num / 2;
  }
  cout << bin << endl;
*/
int n;
cin >> n;
long binary = 0, pow = 1;
while(n > 0) {
int lastBit = n % 2;
binary += lastBit * pow;
pow *= 10;
n = n / 2;
}
cout << binary;
}
