/*
Q. Fibonacci Number

Given a number N, figure out if it is a member of fibonacci series or not. Return true if the number is member of fibonacci series else false.

Fibonacci Series is defined by the recurrence
    F(n) = F(n-1) + F(n-2)
where F(0) = 0 and F(1) = 1

Sample Input 1 :
5

Sample Output 1 :
true

Sample Input 2 :
14

Sample Output 2 :
false    
*/

#include<iostream>
using namespace std;

bool checkMember(int n){
    int a = 0;
    int b = 1;
    int c = 0;
    while(a < n){
        c = a+b;
        a = b;
        b = c;
    }
    return a == n;
}

int main(){
  int n; 
  cin >> n ;
  if(checkMember(n)){
    cout << "true" << endl;
  }else{
    cout << "false" << endl;
  }
  return 0;
}