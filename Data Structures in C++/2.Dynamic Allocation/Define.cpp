#include<iostream>
using namespace std;
#define PI 3.14

int main() {
  int r;
  cin >> r;

  //---------Not_Good---------------//
  cout << 3.14 * r * r << endl;

  double pi = 3.14;
  cout << pi * r * r << endl;
  pi++;
  cout << pi * r * r << endl;

  //---------Not_Good---------------//

  
  cout << PI * r * r << endl;
  //---------Not_Possible_To_Change_Define-------------//
  //PI++;
  //---------Not_Possible_To_Change_Define-------------//
  cout << PI * r * r << endl;
  return 0;
}
