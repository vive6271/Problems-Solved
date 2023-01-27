#include<iostream>
using namespace std;
#include "LinkedListNodeClass.cpp"

void print(Node *head){
  Node *temp = head;
  while(temp != NULL){
    cout << temp -> data << endl;
    temp = temp -> next;
  }
}

int main(){
  Node n1(1), n2(2), n3(3), n4(4), n5(5);
  Node *head = &n1;

  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;

  print(head);

  Node *m1 = new Node(10);
  Node *m2 = new Node(20);
  Node *m3 = new Node(30);
  Node *m4 = new Node(40);
  Node *m5 = new Node(50);

  Node *head2 = m1;

  m1 -> next = m2;
  m2 -> next = m3;
  m3 -> next = m4;
  m4 -> next = m5;

  print(head2);

  return 0;
}
