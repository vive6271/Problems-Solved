template<typename T>
class Node{
public:
  T data;
  Node<T> *next;

  Node(T data){
    this -> data = data;
    this -> next = NULL;
  }
};

template<typename T>
class Queue{
  Node<T> *head;
  Node<T> *tail;
  int size;

public:
  Queue(){
    head = NULL;
    tail = NULL;
    size = 0;
  }

  int getSize(){
    return size;
  }

  bool isEmpty(){
    return size == 0;
  }

  void enqueue(T element){
    Node<T> *newNode = new Node<T>(element);
    if(head == NULL){
      head = newNode;
      tail = newNode;
    }else{
      tail -> next = newNode;
      tail = newNode;
    }
    size++;
  }

  T dequeue(){
    if(isEmpty()){
      cout << "Queue is Empty !" << endl;
      return 0;
    }
    Node<T> *temp = head;
    T tmp = head -> data;
    head = head -> next;
    delete temp;
    size--;
    return tmp;
  }

  T front(){
    if(head == NULL){
      cout << "Queue is Empty !" << endl;
      return 0;
    }
    return head -> data;
  }
};
