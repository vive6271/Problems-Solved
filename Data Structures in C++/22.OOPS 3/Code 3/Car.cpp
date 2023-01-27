class Car : public Vehicle{
    public:
    int maxSpeed;

    /*Works as Car() : Vehicle(){}
      It always calls vehicle's class default constructor. 
      But When we remove vehicle's class default constructor 
      then it gives an error.
      We can use :
      Car() : Vehicle(5){}
      to call Vehicle's class Parametrized Constructor from 
      Car's class default constructor.
    */
    Car(){
        cout << "Car's default Constructor ! " << endl;
    }

    Car(int n) : Vehicle(n){
        cout << "Car's Parametrized Constructor ! " << endl;
    }

    ~Car(){
        cout << "Car's default Destrustor ! " << endl;
    }
};