#include<iostream>
using namespace std;

int max(int a, int b){
  return (a > b) ? a : b;
}

int main(){
  int a,b;
  cin >> a >> b;
  //----------------Not_Good_As_We_are_using_multiple_line---------------------//
  int c;
  if(a > b){
    c = a;
  }else{
    c = b;
  }
  cout << c << endl;
  //-------------------Not_Good_As_We_are_using_multiple_line----------------------//

  //-------------------Its_Good_for_Single_time_Not_for_Multiple_times_as_each_times_we_have_to_write_same_code----------------//
  int d = (a > b) ? a : b;
  cout << d << endl;

  int x,y;
  cin >> x >> y;
  int e = (x > y) ? x : y;
  cout << e << endl;
  //-------------------Its_Good_for_Single_time_Not_for_Multiple_times_as_each_times_we_have_to_write_same_code------------//

  //-------------------Its_Good_for_using_Multiple_times_But_In_this_case_each_times_when_we_call_max-Function_Its_Taking_some_space------------//
  int f = max(a,b);
  cout << f << endl;
  int g = max(x,y);
  cout << g << endl;
  //-------------------Its_Good_for_using_Multiple_times_But_In_this_case_each_times_when_we_call_max-Function_Its_Taking_some_space------------//
}
