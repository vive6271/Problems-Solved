class Student{
  public :
  int rollNumber;

  private :
  int age;

  public :

  Student(int rollNumber, int age){
    cout << "Constructor Called ! " << endl;
    cout << "Adderss of this : " << this << endl;
    this -> rollNumber = rollNumber;
    this -> age = age;
  }
  void display(){
    cout << age << " " << rollNumber << endl;
  }
};
