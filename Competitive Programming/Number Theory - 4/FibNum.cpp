#include<iostream>
using namespace std;

void multiply(int A[2][2], int M[2][2]){
  int Value1 = A[0][0]*M[0][0] + A[0][1]*M[1][0];
  int Value2 = A[0][0]*M[1][0] + A[0][1]*M[1][1];
  int Value3 = A[1][0]*M[0][0] + A[1][1]*M[1][0];
  int Value4 = A[1][0]*M[0][1] + A[1][1]*M[1][1];

  A[0][0] = Value1, A[0][1] = Value2, A[1][0] = Value3, A[1][1] = Value4;
}

void power(int A[2][2], int n){
  if(n == 0 || n == 1){
    return;
  }
  power(A,n/2);

  //Multiply A^n/2 with A^n/2;
  multiply(A,A);
  if(n%2 != 0){
    int M[2][2] = {{1,1},{1,0}};
    //Multiply A^n/2 , A^n/2 and A;
    multiply(A,M);
  }
}

int fib(int n){
  if(n == 0){
    return 0;
  }
  int A[2][2] = {{1,1},{1,0}};
  power(A,n-1);
  return A[0][0];
}

int main(){
  int n;
  cin >> n;
  cout << fib(n) << endl;
  return 0;
}
