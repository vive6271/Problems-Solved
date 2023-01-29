#include<iostream>
using namespace std;

int main(){
  string s = "Vivek";
  string s1(s);
  string s2(s,1,3);

  cout << s << endl << s1 << endl << s2 << endl;

  string s3 = s.substr(0,4);
  if(s2.compare(s3) == 0){
    cout << s2 << " is equal to " << s3 << endl;
  }else{
    cout << s2 << " is not equal to " << s3 << endl;
  }
  return 0;
}
