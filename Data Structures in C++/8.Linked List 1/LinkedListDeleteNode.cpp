/*
Q. Delete node

You have been given a linked list of integers. Your task is to write a function that deletes a node from a given position, 'POS'.
Note :
Assume that the Indexing for the linked list always starts from 0.

If the position is greater than or equal to the length of the linked list, you should return the same linked list without any change.

Input format :
The first line contains an Integer 'T' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the linked list separated by a single space. 

The second line of each test case contains the integer value of 'POS'. It denotes the position in the linked list from where the node has to be deleted.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the resulting linked list of integers in a row, separated by a single space.

Output for every test case will be printed in a separate line.

Sample Input 1 :
1 
3 4 5 2 6 1 9 -1
3

Sample Output 1 :
3 4 5 6 1 9

Sample Input 2 :
2
3 4 5 2 6 1 9 -1
0
10 20 30 40 50 60 -1
7

Sample Output 2 :
4 5 2 6 1 9
10 20 30 40 50 60
*/

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

Node *deleteNode(Node *head, int i){
  Node *temp = head;
  if(i == 0 && head != NULL){
    return head -> next;
  }
  while(temp != NULL && i > 1){
    temp = temp -> next;
    i--;
  }
  if(temp != NULL && temp -> next != NULL){
    Node *a = temp -> next;
    temp -> next = a -> next;
    delete [] a;
  }
  return head;
}
/*
Node *deleteNode(Node *head, int pos){
    // Write your code here.
	Node *tmp = head;
	if(pos == 0 && head != NULL){
		delete head;
		return tmp -> next;
	}
	
	while(tmp != NULL && pos > 1){
		tmp = tmp -> next;
		pos--;
	}

	if(tmp != NULL && tmp -> next != NULL){
		Node *a = tmp -> next;
		tmp -> next = tmp -> next -> next;
		delete a;
	}
	return head;
}
*/

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
  int i;
  cin >> i;
  head = deleteNode(head, i);
  print(head);
  return 0;
}
