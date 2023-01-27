class Student {

  public :
  int rollNumber;

  private :
  int age;

  public :
  void Display(){
    cout << "Age : " << age << " | Roll No : " << rollNumber <<  endl;
  }

  int getAge(){
    return age;
  }

  void setAgePass(int a, int password){
    if(password != 6271 && age < 0){
      return;
    }
    age = a;
  }

  void setAge(int a){
    if(a < 0){
      return;
    }
    age = a;
  }
};
