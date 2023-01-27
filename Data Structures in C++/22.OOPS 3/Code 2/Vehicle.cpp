class Vehicle{
    public:
    int numTyers;

    Vehicle(){
        cout << "Vehicle's default Constructor ! " << endl;
    }

    Vehicle(int n){
        cout << "Vehicle's Parametrized Constructor ! " << endl;
    }

    ~Vehicle(){
        cout << "Vehicle's default Destructor ! " << endl;
    }
};