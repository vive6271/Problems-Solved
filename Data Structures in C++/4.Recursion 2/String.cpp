#include<iostream>
using namespace std;

int main(){
  string* sp = new string;
  *sp = "Hello World";
  cout << sp << endl;
  cout << *sp << endl;

  string s = "abc";
  string s1;
  s1 = "def";
  cout << s << endl;
  cout << s1 << endl;
  return 0;
}
