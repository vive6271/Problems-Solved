class Student{
  public :
  int rollNumber;
  int age;

  static int totalStudents;
  Student(){
    totalStudents++;
  }
};
int Student :: totalStudents = 0;
