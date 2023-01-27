/*
Q. Count Zeros

Given an integer N, count and return the number of zeros that are present in the given integer using recursion.

Sample Input 1 :
0

Sample Output 1 :
1

Sample Input 2 :
00010204

Sample Output 2 :
2

Explanation for Sample Output 2 :
Even though "00010204" has 5 zeros, the output would still be 2 because when you convert it to an integer, it becomes 10204.

Sample Input 3 :
708000

Sample Output 3 :
4

*/

#include<iostream>
using namespace std;
/*
int countZero(int n){
  if(n == 0){
    return 1;
  }
  int smallCalculation = countZero(n/10);
  if(n % 10 == 0){
    smallCalculation++;
  }
  if(n/10 == 0){
    return smallCalculation-1;
  }
  return smallCalculation;
}
*/
int countZero(int n) {
    // Write your code here
    if(n < 9){
        if(n == 0){
            return 1;
        }
        return 0;
    }
    int smallCal = countZero(n/10);
    if(n % 10 == 0){
        return smallCal+1;
    }
    return smallCal;
}
int main(){
  int n;
  cin >> n;
  int output = countZero(n);
  cout << output << endl;
  return 0;
}
