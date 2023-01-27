/*
Q. Merge Two Sorted LL

You have been given two sorted(in ascending order) singly linked lists of integers.
Write a function to merge them in such a way that the resulting singly linked list is also sorted(in ascending order) and return the new head to the list.

Note :
Try solving this in O(1) auxiliary space.

No need to print the list, it has already been taken care.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the first sorted singly linked list separated by a single space. 

The second line of the input contains the elements of the second sorted singly linked list separated by a single space. 

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output :
For each test case/query, print the resulting sorted singly linked list, separated by a single space.

Output for every test case will be printed in a seperate line.

Sample Input 1 :
1
2 5 8 12 -1
3 6 9 -1

Sample Output 1 :
2 3 5 6 8 9 12 

Sample Input 2 :
2
2 5 8 12 -1
3 6 9 -1
10 40 60 60 80 -1
10 20 30 40 50 60 90 100 -1

Sample Output 2 :
2 3 5 6 8 9 12 
10 10 20 30 40 40 50 60 60 60 80 90 100

*/

#include <iostream>

class Node{
public:
	int data;
	Node *next;
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;


Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2){
    //Write your code here
		Node *newHead = NULL;
		if(head1 == NULL){
			return head2;
		}else if(head2 == NULL){
			return head1;
		}else{
			if(head1 -> data < head2 -> data){
				newHead = head1;
				head1 = head1 -> next;
			}else{
				newHead = head2;
				head2 = head2 -> next;
			}
			Node *temp = newHead;
			while(head1 != NULL && head2 != NULL){
				if(head1 -> data < head2 -> data){
					temp -> next = head1;
					temp = head1;
					head1 = head1 -> next;
				}else{
					temp -> next = head2;
					temp = head2;
					head2 = head2 -> next;
				}
			}
			if(head1 != NULL){
				temp -> next = head1;
			}else if(head2 != NULL){
				temp -> next = head2;
			}
		}
		return newHead;
}

/*
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2){
    //Write your code here
	if(!head1){
		return head2;
	}else if(!head2){
		return head1;
	}

	Node *finalHead = NULL, *finalTail = NULL, *tmp;

	while(head1 != NULL && head2 != NULL){
		if(head1 -> data < head2 -> data){
			tmp = head1;
			head1 = head1 -> next;
		}else{
			tmp = head2;
			head2 = head2 -> next;
		}

		if(!finalHead){
			finalHead = tmp;
			finalTail = tmp;
		}else{
			finalTail -> next = tmp;
			finalTail = tmp;
		}
	}

	if(!head1){
		finalTail -> next = head2;
	}else if(!head2){
		finalTail -> next = head1;
	}
	
	return finalHead;
}
*/
Node *takeinput(){
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1){
		Node *newNode = new Node(data);
		if (head == NULL){
			head = newNode;
			tail = newNode;
		}
		else{
			tail->next = newNode;
			tail = newNode;
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
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}
