class Truck : virtual public Vehicle{
    public:

    Truck() : Vehicle(4){
        cout << "Truck's Default Constructor ! " << endl;
    }
/*
    void print(){
        cout << "Truck" << endl;
    }
*/    
    ~Truck(){
        cout << "Truck's Default Destructor ! " << endl;
    }
};