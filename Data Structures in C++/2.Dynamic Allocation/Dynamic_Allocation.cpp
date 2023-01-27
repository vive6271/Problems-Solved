#include<iostream>
using namespace std;

int main(){
  int* p = new int;
  *p = 10;
  cout << *p << endl;

  double *pd = new double;
  *pd = 10.23;
  cout << *pd << endl;

  char *c = new char;
  *c = 'A';
  cout << *c << endl;

  int *pa = new int[50];
  //-----------Total:- 208 Bytes (Stack :- 8 Bytes & Heap :- 200 (4 * 50) Bytes)---------------//
  int n;
  cin >> n;
  int *pa2 = new int[n];

  for(int i = 0; i < n; i++){
    cin >> pa2[i];
  }
  for(int i = 0; i < n; i++){
    cout << pa2[i] << " ";
  }
  cout << endl;
  return 0;
}
