#include <iostream>
using namespace std;

class Bus{
    public:

    void print();
};

void test();

class Car{
    public:

    void print();
    void print2();
    void print3();
    void print4();
};

class Truck{
    private:
    int x;

    protected:
    int y;

    public:
    int z;

    friend void Bus :: print();
    friend void test();
    friend class Car;
};

void Bus :: print(){
    Truck t;
    t.x = 10;
    t.y = 20;
    cout << t.x << " " << t.y << endl;
}

void Car :: print(){
    Truck t;
    t.x = 10;
    t.y = 20;
    cout << t.x << " " << t.y << endl;
}

void Car :: print2(){
    Truck t;
    t.x = 30;
    t.y = 40;
    cout << t.x << " " << t.y << endl;
}

void Car :: print3(){
    Truck t;
    t.x = 50;
    t.y = 60;
    cout << t.x << " " << t.y << endl;
}

void Car :: print4(){
    Truck t;
    t.x = 70;
    t.y = 80;
    cout << t.x << " " << t.y << endl;
}

void test(){
    Truck t;
    t.x = 30;
    t.y = 40;
    cout << t.x << " " << t.y << endl;
}

int main(){
    Bus b;
    b.print();
    
    test();

    Car c;
    c.print();
    c.print2();
    c.print3();
    c.print4();
    return 0;
}