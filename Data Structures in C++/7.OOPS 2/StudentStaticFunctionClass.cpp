class Student{
  static int totalStudents;
  public :
  int rollNumber;
  int age;

  Student(){
    totalStudents++;
  }
  static int getTotalStudent(){
    return totalStudents;
  }
};
int Student :: totalStudents = 0;
