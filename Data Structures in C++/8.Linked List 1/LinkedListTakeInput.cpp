#include<iostream>
using namespace std;
#include "LinkedListNodeClass.cpp"

Node *takeInput() {
  int data;
  cin >> data;
  Node *head = NULL;
  while(data != -1){
    Node *newData = new Node(data);
    if(head == NULL){
      head = newData;
    }else{
      Node *temp = head;
      while(temp -> next != NULL){
        temp = temp -> next;
      }
      temp -> next = newData;
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
  Node *head = takeInput();
  print(head);
  return 0;
}
