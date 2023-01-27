/*
Q. Binary to decimal

Given a binary number as an integer N, convert it into decimal and print.

Sample Input 1 :
1100

Sample Output 1 :
12

Sample Input 2 :
111

Sample Output 2 :
7
*/

#include<iostream>
using namespace std;

int main(){
  int num;
  cin >> num;

  int reminder = 0;
  int sq = 0;
  int bin = 0;
  while(num > 0){
    reminder = num % 10;
    num = num / 10;
    if(sq == 0){
      sq = 1;
    }else{
      sq = 2 * sq;
    }
    bin += (sq * reminder);
  }
  cout << bin << endl;
}
