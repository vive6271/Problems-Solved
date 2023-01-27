#include<iostream>
using namespace std;

int main() {

  //-----------Constant_Vaiable------------//
  int const i = 10;
  const int i2 = 10;

 //----------Constant_reference_from_non_const_int--------//
 int j = 12;
 const int &k = j;
 j++; //  Possible
 //k++; Not_Possible

 cout << k << endl;

 //----------Constant_reference_from_const_int---------//
 int const j2 = 13;
 int const & k2 = j2;

 //j2++; Not_Possible
 //k2++;  Not_Possible

 //----------Reference_from_const_int-----------------//
 int const j3 = 15;
 //int & k3 = j3; Not_Possible
 //---Note :- If "int & k3 = j3" is Possible then "k3++" also have to be Possible----//
 return 0;
}
