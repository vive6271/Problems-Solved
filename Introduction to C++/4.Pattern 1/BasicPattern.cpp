#include<iostream>
using namespace std;

int main() {
  int n;

  cout << " Enter value of N " << endl;
  cin >> n;

  int i = 1;
  while(i <= n) {
    int j = 1;
    while(j <= n) {
      cout << "*" ;
      j++;
    }
    cout << endl;
    i++;
  }
}
