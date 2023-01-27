#include<iostream>
using namespace std;

int main(){
  int n;
  cin >> n;

  int input[10];

  for(int i = 0; i < n ; i++){
    cin >> input[i];
  }

  for(int j = 0; j < 10; j++){
    cout << input[j] << endl;
  }
}
