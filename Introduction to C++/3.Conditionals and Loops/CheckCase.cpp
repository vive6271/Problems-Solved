/*
Q. Check Case

Write a program that takes a character as input and prints either 1, 0 or -1 according to the following rules.
1, if the character is an uppercase alphabet (A - Z)
0, if the character is a lowercase alphabet (a - z)
-1, if the character is not an alphabet

Sample Input 1 :
v

Sample Output 1 :
0

Sample Input 2 :
V

Sample Output 2 :
1

Sample Input 3 :
#

Sample Output 3 :
-1
*/
#include <iostream>
using namespace std;
int main() {
    char c ;
    cout << "Enter any alphabet" << endl;
    cin >> c;
    int a = c;

    cout << a << endl;

    if (a >= 65 && a <= 90 ) {
      cout << "1" << endl;
    }else if (a >=97 && a <= 122) {
      cout << "0" << endl;
    }else {
      cout << "-1" << endl;
    }
}
