/*
Q.All Prime Numbers

Given an integer N, print all the prime numbers that lie in the range 2 to N (both inclusive).
Print the prime numbers in different lines.

Sample Input 1:
9

Sample Output 1:
2
3
5
7

Sample Input 2:
20

Sample Output 2:
2
3
5
7
11
13
17
19
*/

#include<iostream>
using namespace std;

int main() {
  int n;

  cin >> n;

  int i = 2;
  while(i <= n){
    int d = 2;
    bool isPrime = true;
    while(d < i){
      if(i % d == 0){
        isPrime = false;
        break;
      }
      d++;
    }
    if(isPrime){
      cout << i << endl;
    }
    i++;
  }


  cout << endl << endl;



  for(int a = 2; a <= n; a++){
    bool isPrime = true;
    for(int b = 2; b < a ; b++){
      if(a % b == 0){
        isPrime = false;
        break;
      }
    }
    if(isPrime){
      cout << a << endl;
    }
  }
}
