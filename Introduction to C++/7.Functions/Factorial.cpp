#include<iostream>
using namespace std;

int main() {
  int n , r;
  cin >> n >> r;

  int i = 1;
  int fact_n = 1;
  while(i <= n){
    fact_n *= i;
    i++;
  }

  i = 1;
  int fact_r = 1;
  while(i <= r){
    fact_r *= i;
    i++;
  }

  i = 1;
  int fact_n_r = 1;
  while(i <= n-r){
    fact_n_r *= i;
    i++;
  }

  cout << fact_n/(fact_r * fact_n_r) << endl;
}
