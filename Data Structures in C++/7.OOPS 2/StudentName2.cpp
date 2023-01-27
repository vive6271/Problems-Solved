#include<iostream>
using namespace std;
#include<cstring>
#include "StudentNameClass2.cpp"

int main(){
	char name[] =  "abcd";
	Student s1(20,name);
	s1.Display();

	Student s2(s1);

	s2.name[0] = 'x';
	s1.Display();
	s2.Display();

	return 0;
}
