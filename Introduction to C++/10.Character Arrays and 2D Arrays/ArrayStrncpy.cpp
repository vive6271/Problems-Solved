#include<iostream>
#include<cstring>
using namespace std;

int main(){
  char input1[100], input2[100];

  cin.getline( input1, 100);
  cin.getline( input2, 100);

  strncpy( input1, input2, 3);

  cout << input1 << endl;
}
