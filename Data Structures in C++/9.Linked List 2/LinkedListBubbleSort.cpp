/*
Q. Bubble Sort (Iterative) LinkedList

Given a singly linked list of integers, sort it using 'Bubble Sort.'

Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.

Sample Input 1 :
10 9 8 7 6 5 4 3 -1

Sample Output 1 :
3 4 5 6 7 8 9 10 

Sample Input 2 :
10 -5 9 90 5 67 1 89 -1

Sample Output 2 :
-5 1 5 9 10 67 89 90 

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

Node *swapNode(Node *n1, Node *n2){
	Node *head = n2;
	n1 -> next = n2 -> next;
	n2 -> next = n1;
	return head;
}

int len(Node* head){
	int count = 0;
	while(head){
		head = head -> next;
		count++;
	}
	return count;
}

Node *bubbleSort(Node *head){
	// Write your code here
	if(head == NULL || head -> next == NULL){
		return head;
	}
	Node *cNode = NULL, *pNode = NULL, *stopNode = NULL;
	int n = len(head);
	for(int i = 0; i < n; i++){
		cNode = head,
		pNode = NULL;
		while(cNode -> next != stopNode){
			if(cNode -> data > (cNode -> next) -> data){
				Node *tmp = swapNode(cNode, cNode -> next);
				if(!pNode){
					head = tmp;
					pNode = tmp;
				}else{
					pNode -> next = tmp;
					pNode = tmp;
				}
				/* No need to increment or move cNode to cNode -> next.
				   After, swapping both Nodes "cNode" automatically incremented
				   to "cNode -> next".
				*/
			}else{
				pNode = cNode;
				cNode = cNode -> next;
			}
		}
		stopNode = cNode;
	}
	return head;
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
		}else{
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
	Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
}
