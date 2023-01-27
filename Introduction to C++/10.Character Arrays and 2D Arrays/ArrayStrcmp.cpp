#include<iostream>
#include<cstring>
using namespace std;

int main(){
  char input1[100];
  char input2[100];

  cin.getline( input1, 100);
  cin.getline( input2, 100);

  int isSame = strcmp( input1, input2);

  if(isSame == 0){
    cout << "True" << endl;
  }else{
    cout << "False" << endl;
  }
}
