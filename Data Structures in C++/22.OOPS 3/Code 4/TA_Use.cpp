#include <iostream>
using namespace std;
#include "Teacher.cpp"
#include "Student.cpp"
#include "TA.cpp"

int main(){
    TA a;
    a.print();
    a.name = "Ram";
    a.age = 20;

    cout << "TA's Name : " << a.name << endl;
    cout << "TA's Age : " << a.age << endl;

    a.Teacher :: name = "Akash";
    a.Teacher :: age = 35;
    a.sub = "English";

    cout << "Teacher's Name : " << a.Teacher :: name << endl;
    cout << "Teacher's Age : " << a.Teacher :: age << endl;
    cout << "Teacher's Sub : " << a.sub << endl;

    a.Student :: name = "Ajay";
    a.Student :: age = 18;
    a.rollNum = 102;

    cout << "Student's Name : " << a.Student :: name << endl;
    cout << "Student's Age : " << a.Student :: age << endl;
    cout << "Student's Roll No : " << a.rollNum << endl;
    return 0;
}