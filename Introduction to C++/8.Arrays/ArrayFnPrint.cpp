#include<iostream>
using namespace std;

void printArray(int input[] , int n){
  for(int j = 0; j < n; j++){
    cout << input[j] << " ";
  }
  cout << endl;
}

int main(){
  int n;
  cin >> n;

  int input[10];

  for(int i = 0; i < n; i++){
    cin >> input[i];
  }
  printArray( input , n );
}
