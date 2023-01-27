class Teacher{
    public:
    int age;
    string name;
    string sub;
    
    Teacher(){
        cout << "Teacher's default Constructor ! " << endl;
    }

    void print(){
        cout << "Teacher" << endl;
    } 
    ~Teacher(){
        cout << "Teacher's default Destructor ! " << endl;
    }
};