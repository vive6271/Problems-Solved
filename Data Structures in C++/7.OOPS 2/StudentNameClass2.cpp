class Student{
	int age;

	public:
		char *name;
		Student(int age, char *name){
			this -> age = age;
			//Shallow Copy
			//this -> name = name;

			//Deep Copy
			this -> name = new char[strlen(name) + 1];
			strcpy(this -> name, name);
		}

		//Copy Constructor

		Student(Student const &s){
			this -> age = s.age;
			//Shallow Copy
			//this -> name = s.name;

			//Deep Copy
			this -> name = new char[strlen(s.name)+1];
			strcpy(this -> name, s.name);
		}

	void Display(){
	    cout << age << " " << name << endl;
	}
};
