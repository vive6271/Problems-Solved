#include<iostream>
using namespace std;

int power(int a, int b, int c){
  if(a == 0){
    return 0;
  }
  if(b == 0){
    return 1;
  }
  long ans;
  if((b%2) == 0){
    long smallAns = power(a, b/2, c);
    ans = (smallAns * smallAns) % c;
  }else{
    long smallAns = power(a, b-1, c);
    ans = (a % c);
    ans = (ans * smallAns) % c;
  }
  return int ((ans + c) % c);
}

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  cout << power(a,b,c) << endl;
  return 0;
}
