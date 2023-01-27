#include<iostream>
using namespace std;
#include "TemplateClass2.cpp"

int main(){
  Pair<int, double> p1;

  p1.setX(100.34);
  p1.setY(100.34);

  cout << p1.getX() << " " << p1.getY() << endl;

  return 0;
}
