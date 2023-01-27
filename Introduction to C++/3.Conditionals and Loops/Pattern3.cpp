#include <iostream>
using namespace std;

int main() {
  int n;

  cout << "Enter value of N" << endl;
  cin >> n;

  int i = 1;
  int val = 1;

  while(i <= n) {
    int k = 1;
    while(k <= n - i){
      cout << " " ;
      k += 1;
    }

    int j = 1;
    while(j <= i) {
      cout << val;
      val += 1;
      j += 1;
    }
    cout << endl;
    i += 1;
  }
}
