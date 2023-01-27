#include<iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int input[10];

  for(int i = 0; i < n; i++){
    cin >> input[i];
  }

  int max = input[0];
  for(int j = 1; j < n; j++){
    if(input[j] > max){
      max = input[j];
    }
  }
  cout << max << endl;
}
