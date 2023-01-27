#include<iostream>
using namespace std;

void increment(int n){
  n++;
}

void incrementRef(int& n){
  n++;
}

int main(){
  int i = 10;

  increment(i);
  cout << i << endl;

  incrementRef(i);
  cout << i << endl;

  int& j = i;
  i++;
  cout << j << endl;
  j++;
  cout << i << endl;
  int k = 100;
  j = k;
  cout << i << endl;
  return 0;
}
