class Vehicle{
    private:
    int maxSpeed;

    public:

    Vehicle(){
        cout << "Vehicle's Default Constructor ! " << endl;
    }

    void print(){
        cout << "Vehicle" << endl;
    }

    Vehicle(int n){
        cout << "Vehicle's Parametrized Constructor ! " << endl;
        maxSpeed = n;
    }

    ~Vehicle(){
        cout << "Vehicle's Default Destructor ! " << endl;
    }
};