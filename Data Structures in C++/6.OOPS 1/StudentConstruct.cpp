class Student{
  public :
  int rollNumber;

  private :
  int age;

  public :

  //Default Constructor
  Student() {
    cout << "Constructor Called ! " << endl;
  }

  //Parameterized Constructor
  Student(int r){
    cout << "Constructor 2 Called ! " << endl;
    rollNumber = r;
  }

  Student(int a, int r){
    cout << "Constructor 3 Called ! " << endl;
    age = a;
    rollNumber = r;
  }
  void display(){
    cout << age << " " << rollNumber << endl;
  }


};
