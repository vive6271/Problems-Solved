#include<iostream>
using namespace std;
#include "Vehicle.cpp"
#include "Car.cpp"

int main(){
    Car c;
    c.color = "Black";
    //c.numTyers = 4; //Not accessable 
    c.numGears = 5;

    cout << c.color << endl;
    cout << c.numGears << endl;
    c.print();
    return 0;
}