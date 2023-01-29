#include<iostream>
using namespace std;

int main(){
  int n, count = 0;
  cin >> n;

  int *superPrime = new int[n+1];
  for(int i = 0; i < n; i++){
    superPrime[i] = 0;
  }

  for(int i = 2; i <= n; i++){
    if(!superPrime[i]){
      for(int j = 2*i; j <= n; j += i){
        superPrime[j]++;
      }
    }
  }
  for(int i = 1; i <= n; i++){
    if(superPrime[i] == 2){
      count++;
    }
  }
  cout << count << endl;
  delete [] superPrime;
  return 0;
}
