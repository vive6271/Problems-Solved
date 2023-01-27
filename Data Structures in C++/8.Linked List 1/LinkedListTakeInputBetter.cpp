#include<iostream>
using namespace std;
#include "LinkedListNodeClass.cpp"

Node *takeInput_Better() {
  int data;
  cin >> data;
  Node *head = NULL;
  Node *tail = NULL;
  while(data != -1){
    Node *newData = new Node(data);
    if(head == NULL){
      head = newData;
      tail = newData;
    }else{
      tail -> next = newData;
      tail = tail -> next;
      // OR
      // tail = newData; 
    }
    cin >> data;
  }
  return head;
}

void print(Node *head){
  while(head != NULL){
    cout << head -> data << " ";
    head = head -> next;
  }
  cout << endl;
}

int main(){
  Node *head = takeInput_Better();
  print(head);
  return 0;
}
