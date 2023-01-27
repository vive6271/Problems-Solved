#include<iostream>
using namespace std;

int& f(int n){
  int a = n;
  return a;
}

int* f2(int n){
  int i = 10;
  return &i;
}

int main(){
  int i = 10;
  int& k = f(i);
  cout << k << endl;

  int* p = f2(i);
  cout << p << endl;
  return 0;
}
