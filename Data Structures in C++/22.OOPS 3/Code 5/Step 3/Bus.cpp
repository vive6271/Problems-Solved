class Bus : public Car, public Truck{
    public:

    Bus() : Vehicle(5){
        cout << "Bus's Default Constructor ! " << endl;
    }
/*
    void print(){
        cout << "Bus" << endl;
    }
*/
    ~Bus(){
        cout << "Bus's Default Destructor ! " << endl;
    }
};