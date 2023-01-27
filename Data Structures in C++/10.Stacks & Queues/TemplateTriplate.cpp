#include<iostream>
using namespace std;
#include "TemplateClass2.cpp"

int main(){
  Pair<Pair<int, int>, int> p2;
  p2.setY(10);

  Pair<int, int> p4;
  p4.setX(15);
  p4.setY(16);

  p2.setX(p4);

  cout << p2.getX().getX() << " " << p2.getX().getY() << " " << p2.getY() << endl;
  return 0;
}
