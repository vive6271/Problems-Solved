#include<iostream>
using namespace std;
#include "LinkedListNodeClass.cpp"

int main(){
  //Static
  Node n1(1);
  Node *head = &n1;

  Node n2(2);
  n1.next = &n2;

  cout << n1.data << " " << n2.data << endl;

  cout << head -> data << endl;

  //Dynamic

  Node *n3 = new Node(10);
  Node *head2 = n3;

  Node *n4 = new Node(20);

  n3 -> next = n4;

  cout << n3 -> data << " " << n4 -> data << endl;
  cout << head2 -> data << endl;
  return 0;
}
