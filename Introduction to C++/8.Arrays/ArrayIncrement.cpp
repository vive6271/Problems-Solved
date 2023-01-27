#include<iostream>
using namespace std;

void increment(int b[] , int a , int n){
  b[0]++;
  a++;
}

int main(){
  int a = 10;
  int b[10] = { 1, 2, 3, 4};

  increment(b, a, 10);
  cout << "a : " << a << endl;
  cout << "b[0] : " << b[0] << endl;
}
