using namespace std;

template<typename T>
class Node{
public:
  T data;
  Node<T> *next;

  Node(T data){
    this -> data = data;
    next = NULL;
  }
};

template<typename T>
class Stack{
  Node<T> *head;
  int size;

public:
  Stack(){
    head = NULL;
    size = 0;
  }

  int getSize(){
    return size;
  }

  bool isEmpty(){
    return size == 0;
  }

  void push(T element){
    Node<T> *newNode = new Node<T>(element);
    newNode -> next = head;
    head = newNode;
    size++;
  }

  T pop(){
    if(head == NULL){
      cout << "Stack is Empty" << endl;
      return -1;
    }
    Node<T> *temp = head;
    T ans = head -> data;
    head = head -> next;
    delete temp;
    size--;
    return ans;
  }

  T top(){
    if(head == NULL){
      cout << "Stack is Empty" << endl;
      return -1;
    }
    return head -> data;
  }
};
