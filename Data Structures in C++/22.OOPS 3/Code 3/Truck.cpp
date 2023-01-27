class Truck : public Vehicle{
    public:
    int topSpeed;

    Truck(){
        cout << "Truck's default Constructor ! " << endl;
    }

    ~Truck(){
        cout << "Truck's default Destructor ! " << endl;
    }
};