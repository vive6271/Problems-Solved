#include<iostream>
#include<cstring>
using namespace std;

int main() {
  char input[100];
  cin.getline(input, 100);

  int length = strlen(input);
  cout << length << endl;
}
