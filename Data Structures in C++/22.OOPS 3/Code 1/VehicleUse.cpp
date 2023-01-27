#include<iostream>
using namespace std;
#include "Vehicle.cpp"

int main(){
    Vehicle v;
    v.color = "Blue";
    //v.maxSpeed = 100;  //Not accessable
    //v.numTyers = 4;  //Not accessable
    cout << v.color << endl;
    return 0;
}