class Student{
    public:
    string name;
    int age;
    int rollNum;

    Student(){
        cout << "Student's default Constructor !" << endl;
    }

    void print(){
        cout << "Student" << endl;
    }
    ~Student(){
        cout << "Student's default Destructor !" << endl;
    }
};