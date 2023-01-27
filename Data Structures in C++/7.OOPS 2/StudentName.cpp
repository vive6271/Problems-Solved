#include<iostream>
using namespace std;
#include<cstring>
#include "StudentNameClass.cpp"

int main(){
	char name[] =  "abcd";
	Student s1(20,name);
	s1.Display();

	name[3] = 'e';
	Student  s2(24,name);
	s2.Display();

	s1.Display();
	return 0;
}
