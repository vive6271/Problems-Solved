class Student{
  public :
  int rollNumber;

  private :
  int age;

  public :

  Student(){
    cout << "Constructor Called ! " << endl;
  }

  ~Student(){
    cout << "Destructor Called ! " << endl;
  }
  
  Student(int a, int r){
    cout << "Constructor 2 Called ! " << endl;
    this -> age = a;
    this -> rollNumber = r;
  }
  void display(){
    cout << age << " " << rollNumber << endl;
  }
};
