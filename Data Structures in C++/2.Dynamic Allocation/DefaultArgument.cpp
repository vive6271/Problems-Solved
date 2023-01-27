#include<iostream>
using namespace std;

int sum(int a, int b = 0, int c = 0, int d = 0){
  return (a+b+c+d);
}

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << "Only A : " << sum(a) << endl;
  cout << "Sum of A and B : " << sum(a,b) << endl;
  cout << "Sum of A , B and C : " << sum(a,b,c) << endl;
  cout << "Sum of A , B , C and D : " << sum(a,b,c,d) << endl;
  return 0; 
}
