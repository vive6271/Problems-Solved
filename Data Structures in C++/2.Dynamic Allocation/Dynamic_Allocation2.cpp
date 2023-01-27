#include<iostream>
using namespace std;

int main() {
  int *p = new int;
  delete p;

  p = new int;
  delete p;

  p = new int[100];
  delete [] p;

  /*

  while(true){
  int i = 10;
  }

  //---------------------Bad_Code_As- it's not clearing older memory location (Heap) which is assign to its ------------------//

  while(true){
  int *p = new int;
  }
  */
}
