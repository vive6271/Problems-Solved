#include<iostream>
using namespace std;

void Print(int n){
  for(int i = 1; i <= n; i++){
    cout << i << endl;
  }
}

int main(){
  int n;
  cin >> n;

  Print(n); // As we are using "void" which does not return any value. so that no need to store it;
}
