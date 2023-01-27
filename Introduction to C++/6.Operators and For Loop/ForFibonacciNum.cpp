/*
Q. Nth Fibonacci Number

Nth term of Fibonacci series F(n), where F(n) is a function, is calculated using the following formula -
    F(n) = F(n-1) + F(n-2), 
    Where, F(1) =  1, 
           F(2) = 1

Provided N you have to find out the Nth Fibonacci Number.

Sample Input 1:
6

Sample Output 1:
8

Explanation of Sample Input 1:

Now the number is ‘6’ so we have to find the “6th” Fibonacci number
So by using the property of the Fibonacci series i.e 

[ 1, 1, 2, 3, 5, 8, 13, 21]
So the “6th” element is “8” hence we get the output.
*/

#include<iostream>
using namespace std;

int main() {
  int n ;

  cin >> n;

  int n1 = 0;
  int n2 = 1;
  int nsum = 1;
  for(int i = 1; i < n; i++){
    nsum = n1 + n2;
    n1 = n2;
    n2 = nsum;
  }
  cout << nsum << endl;
}
