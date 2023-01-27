#include<iostream>
using namespace std;
#include "StudentConstInBuilt.cpp"

int main(){
    Student s1(10,101);
    Student s2(20,102);
    
    Student *s3 = new Student(30,103);
    cout << "S1 : ";
    s1.display();

    cout << "S2 : ";
    s2.display();

    cout << "S3 : ";
    s3 -> display();

    s2 = s1;
    cout << "S2 : ";
    s2.display();

    *s3 = s1;
    cout << "S3 : ";
    s3 -> display();

    s2 = *s3;
    cout << "S2 : ";
    s2.display();
}