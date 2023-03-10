/*
Q. Even after Odd LinkedList

For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. 
The relative order of the odd and even terms should remain unchanged.

Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Input format:
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space. 
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format:
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.

Sample Input 1 :
1
1 4 5 2 -1

Sample Output 1 :
1 5 4 2 

Sample Input 2 :
2
1 11 3 6 8 0 9 -1
10 20 30 40 -1

Sample Output 2 :
1 11 3 9 6 8 0
10 20 30 40

*/

#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node *next;
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

Node *evenAfterOdd(Node *head){
	//write your code here
  if(head == NULL || head -> next == NULL){
    return head;
  }
  Node *temp = head, *oddHead = NULL, *oddTail = NULL, *evenHead = NULL, *evenTail = NULL;
  while(temp != NULL){
    if(temp -> data % 2 == 1){
      if(oddHead == NULL){
        oddHead = temp;
        oddTail = temp;
      }else{
        oddTail -> next = temp;
        oddTail = temp;
      }
    }else{
      if(evenHead == NULL){
        evenHead = temp;
        evenTail = temp;
      }else{
        evenTail -> next = temp;
        evenTail = temp;
      }
    }
    temp = temp -> next;
  }
  if(evenTail == NULL){
    oddTail -> next = NULL;
    return oddHead;
  }else if(oddTail == NULL){
    evenTail -> next = NULL;
    return evenHead;
  }else{
    oddTail -> next  = evenHead;
    evenTail -> next = NULL;
  }
  return oddHead;
}

Node *takeinput(){
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1){
		Node *newnode = new Node(data);
		if (head == NULL){
			head = newnode;
			tail = newnode;
		}
		else{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head){
	Node *temp = head;
	while (temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	while (t--){
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}
