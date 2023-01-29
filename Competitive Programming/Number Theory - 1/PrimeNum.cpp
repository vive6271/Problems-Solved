#include<iostream>
using namespace std;
//Sieve of Eratosthenes
int main(){
  int n, count = 0;
  cin >> n;
  bool *prime = new bool[n+1];
  prime[0] = false;
  prime[1] = false;
  for(int i = 2; i <= n; i++){
    prime[i] = true;
  }

  for(int i = 2; i*i <= n; i++){
    if(prime[i]){
      for(int j = i*i; j <= n; j+= i){
        prime[j] = false;
      }
    }
  }
  for(int i = 0; i <= n; i++){
    if(prime[i]){
      count++;
    }
  }
  cout << count << endl;
  delete [] prime;
  return 0;
}
/* Too slow
bool checkPrime(int n){
  int count = 0;
  for(int i = 1; i*i <= n; i++){
    if(n%i == 0){
      if(i*i == n){
        count++;
        continue;
      }
      count += 2;
    }
  }
  return count == 2;
}

int main(){
  int n, count = 0;
  cin >> n;
  for(int i = 1; i <= n; i++){
    if(checkPrime(i)){
      count++;
    }
  }
  cout << count << endl;
  return 0;
}
*/
