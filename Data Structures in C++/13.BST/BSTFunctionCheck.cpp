#include<iostream>
#include "BinarySearchTree.h"
using namespace std;
int main(){
  BST *b = new BST();
  char ch = 'Y';
  cout << "***  1.Insert  2.Delete  ***" << endl;
  while(ch == 'Y'){
    int n;
    cout << "Press Action [1/2]: ";
    cin >> n;
    if(n == 1){
      int nodeData;
      cout << "Insert Data to BST : ";
      cin >> nodeData;
      b -> insertData(nodeData);
    }else if(n == 2){
      int nodeData;
      cout << "Delete Data from BST : ";
      cin >> nodeData;
      b -> deleteData(nodeData);
    }
    cout << "Do you want to continue [Y/N] : ";
    cin >> ch;
    if(ch == 'N'){
      break;
    }
  }
  b -> printLevelWise();
  return 0;
}
