#include <iostream>
using namespace std;
#include "Vehicle.cpp"
#include "Car.cpp"

int main(){
    Vehicle v;

    Car c;

    v.print();
    c.print();

    Vehicle *v1 = new Vehicle;

    Vehicle *v2;
    //v2 = &v;

    v2 = &c; // Allowed

    v1 -> print();

    v2 -> print();

    Car *c2;

    //c2 = &v; Not Allowed;
    return 0;
}