#include <iostream>
using namespace std;

int main() {
  int n ;

  std::cout << "Enter value of N" << endl;
  std::cin >> n;

  int i = 1;
  while(i <= n) {
    int j = 1;
    while(j <= i){
      cout << j;
      j = j + 1;
    }
    cout << endl;
    i = i + 1;
  }
}
