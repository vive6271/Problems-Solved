class Node {
  public :
  int data;
  Node *next;

  Node(int data) {
      this->data = data;
      next = NULL;
  }
};

class Stack {
	// Define the data members
    Node *head;
    int size;
   public:
    Stack() {
        // Implement the Constructor
        head = NULL;
        size = 0;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return size == 0;
    }

    void push(int element) {
        // Implement the push() function
        Node *newNode = new Node(element);
        size++;
        if(head == NULL){
        head = newNode;
        return;
        }
        newNode -> next = head;
        head = newNode;
    }

    int pop() {
        // Implement the pop() function
        if(head == NULL){
            return -1;
        }
        size--;
        Node *temp = head;
        int tmp = head -> data;
        head = head -> next;
        delete temp;
        return tmp;
    }

    int top() {
        // Implement the top() function
        if(head == NULL){
            return -1;
        }
        return head -> data;
    }
};
