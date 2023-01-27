/*
Q. Palindrome LinkedList

You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First and the only line of each test case or query contains the the elements of the singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.

Output format :
For each test case, the only line of output that print 'true' if the list is Palindrome or 'false' otherwise.

Sample Input 1 :
1
9 2 3 3 2 9 -1

Sample Output 1 :
true

Sample Input 2 :
2
0 2 3 2 5 -1
-1

Sample Output 2 :
false
true

Explanation for the Sample Input 2 :
For the first query, it is pretty intuitive that the the given list is not a palindrome, hence the output is 'false'.

For the second query, the list is empty. An empty list is always a palindrome , hence the output is 'true'.
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

bool isPalindrome(Node *head){
    //Write your code here
		int nLength = 0;
		Node *temp = head, *midNode = NULL;
		while(temp != NULL){
			temp = temp -> next;
			nLength++;
		}
		if(nLength == 0 || nLength == 1){
      return true;
    }
		int fPart = nLength/2, lPart = nLength - fPart;
		midNode = head;
		for(int i = 0; i < fPart; i++){
			midNode = midNode -> next;
		}
		if(nLength % 2 == 1){
			lPart--;
			midNode = midNode -> next;
		}
		temp = midNode;
		Node *currNode = NULL, *nextAdd = NULL;
		for(int i = 0; i < lPart-1; i++){
			currNode = temp;
			temp = temp -> next;
			currNode -> next = nextAdd;
			nextAdd = currNode;
		}
		temp -> next = nextAdd;
		midNode = temp;
		while(fPart--){
			if(head -> data != midNode -> data){
				return false;
			}
			head = head -> next;
			midNode = midNode -> next;
		}
		return true;
}


/*
Node *revesreLL(Node *head){
	if(head == NULL || head -> next == NULL){
		return head;
	}
	Node *tail = head -> next;
	Node *newHead = revesreLL(head -> next);
	tail -> next = head;
	head -> next = NULL;
	return newHead;
}

bool isPalindrome(Node *head){
    //Write your code here
	if(head == NULL || head -> next == NULL){
		return true;
	}

	Node *fast = head, *slow = head;
	while(fast -> next != NULL && fast -> next -> next != NULL){
		slow = slow -> next;
		fast = fast -> next -> next;
	}
	Node *head1 = head;
	Node *head2 = revesreLL(slow -> next);
	slow -> next = NULL;
	while(head1 != NULL && head2 != NULL){
		if(head1 -> data != head2 -> data){
			return false;
		}
		head1 = head1 -> next;
		head2 = head2 -> next;
	}
	return true;
}
*/
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

int main(){
	int t;
	cin >> t;

	while (t--){
		Node *head = takeinput();
		bool ans = isPalindrome(head);
		if (ans) cout << "true";
		else cout << "false";
		cout << endl;
	}
	return 0;
}
