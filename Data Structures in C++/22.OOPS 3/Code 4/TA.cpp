class TA : public Teacher, public Student{
     public:
     int age;
     string name;

     TA(){
        cout << "TA's default Constructor ! " << endl;
     }
     void print(){
        cout << "TA" << endl;
     }
     ~TA(){
        cout << "TA's default Destructor ! " << endl;
     }
};