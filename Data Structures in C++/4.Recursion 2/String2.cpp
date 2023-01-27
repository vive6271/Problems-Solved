#include<iostream>
using namespace std;

int main(){
  string s1, s2;
  s1 = "abc";
  s2 = "def";
  cout << s1+s2 << endl;
  cout << s1[0] << endl;
  s1[0] = 'd';
  cout << s1 << endl;
  s1 += s2;
  cout << s1 << endl;

  cout << s1.size() << endl;
  cout << s1.substr(3) << endl;
  cout << s1.substr(2,3) << endl;

  cout << s1.find("cd") << endl;
  return 0;
}
