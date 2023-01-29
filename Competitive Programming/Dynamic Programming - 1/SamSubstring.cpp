#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
/*
 * Complete the 'substrings' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING n as parameter.
 */

int substrings(string n) {
  long long sum = n[0]-'0';
  long long prevNum = sum;
  for(int i = 1; i < n.length(); i++){
    prevNum = ((prevNum*10) + ((n[i]-'0') * (i+1))) % MOD;
    sum = (sum+prevNum) % MOD;
  }
  return sum;
}

int main(){
    string n;
    getline(cin, n);
    int result = substrings(n);
    cout << result << "\n";
    return 0;
}
