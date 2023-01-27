class Car : virtual public Vehicle{
    public:
    int numGears;

    Car() : Vehicle(3){
        cout << "Car's Default Constructor ! " << endl;
    }

/*
    void print(){
        cout << "Car" << endl;
    }
*/
    ~Car(){
        cout << "Car's Default Destructor ! " << endl;
    }
};