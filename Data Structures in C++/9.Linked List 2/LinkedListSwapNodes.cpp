/*
Q. Swap two Nodes of LL

You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th' and 'j-th' positions.


Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'i,' and 'j,' respectively. A single space will separate them.

Remember/consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.

Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3 4

Sample Output 1 :
3 4 5 6 2 1 9 

Sample Input 2 :
2
10 20 30 40 -1
1 2
70 80 90 25 65 85 90 -1
0 6

Sample Output 2 :
10 30 20 40 
90 80 90 25 65 85 70 

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
Node *swapNodes(Node *head, int i, int j){
	//Write your code here
	if(head == NULL || head -> next == NULL || i == j){
		return head;
	}
	Node *temp = head, *pNode = NULL, *cNode = NULL, *pNode2 = NULL, *cNode2 = NULL;
	if(i > j){
		int temp = i;
		i = j;
		j = temp;
	}
	if(i == 0){
		cNode = head;
		int count = 0;
		while(count < j && temp != NULL){
			pNode2 = temp;
			temp = temp -> next;
			count++;
		}
		cNode2 = temp;
		if(j-i == 1){
			Node *tmp = cNode2 -> next;
			head = cNode2;
			cNode2 -> next = cNode;
			cNode -> next = tmp;
		}else{
			Node* tmp = cNode2 -> next;
			head = cNode2;
			cNode2 -> next = cNode -> next;
			pNode2 -> next = cNode;
			cNode -> next = tmp;
		}
	}else{
		int count = 0;
		while(count < j && temp != NULL){
			if(count == i-1){
				pNode = temp;
			}else if(count == i){
				cNode = temp;
			}
			pNode2 = temp;
			temp = temp -> next;
			count++;
		}
		cNode2 = temp;
		Node *tmp = cNode2 -> next;
		pNode -> next = cNode2;
		pNode2 -> next = cNode;
		cNode2 -> next = cNode -> next;
		cNode -> next = tmp;
	}
	return head;
}
Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}
