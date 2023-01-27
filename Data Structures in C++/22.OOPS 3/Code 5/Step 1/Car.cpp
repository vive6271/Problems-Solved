class Car : public Vehicle{
    public:
    int numGears;

    Car(){
        cout << "Car's Default Constructor ! " << endl;
    }

    void print(){
        cout << "Car" << endl;
    }

    ~Car(){
        cout << "Car's Default Destructor ! " << endl;
    }
};