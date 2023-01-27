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

Node* insertNode(Node *head, int i, int data){
  Node *newNode = new Node(data);
  int count = 0;
  Node *temp = head;

  if(i == 0){
    newNode -> next = head;
    head = newNode;
    return head;
  }

  while(temp != NULL && count < i-1){
    temp = temp -> next;
    count++;
  }

  if(temp != NULL){
    Node *a = temp -> next;
    temp -> next = newNode;
    newNode -> next = a;
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
  int i, data;

  cin >> i >> data;
  head = insertNode(head, i, data);
  print(head);

  return 0;
}
