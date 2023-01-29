#include<iostream>
#include<set>
using namespace std;

int main(){
  int n;
  cin >> n;
  bool *prime = new bool[n+1];
  for(int i = 0; i <= n; i++){
    prime[i] = true;
  }
  prime[0] = false;
  prime[1] = false;
  for(int i = 2; i*i <= n; i++){
    if(prime[i]){
      for(int j = i*i; j <= n; j += i){
        prime[j] = false;
      }
    }
  }
  int count = 0;
  set<int> s;
  for(int i = 2; i <= n; i++){
    if(prime[i]){
      s.insert(i);
    }
  }
  set<int> :: iterator it;
  for(it = ++s.begin(); it != s.end(); it++){
    int a = *(--it);
    int b = *(++it);
    if(s.find(a+b+1) != s.end()){
      count++;
    }
  }
  cout << count << endl;
  delete [] prime;
  return 0;
}
