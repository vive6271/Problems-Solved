/*
Q. Check Number sequence

You are given S, a sequence of n integers i.e. S = s1, s2, ..., sn. Compute if it is possible to split S into two parts : s1, s2, ..., si and si+1, si+2, ….., sn (0 <= i <= n) in such a way that the first part is strictly decreasing while the second is strictly increasing one.

Note : We say that x is strictly larger than y when x > y.
So, a strictly increasing sequence can be 1 4 8. However, 1 4 4 is NOT a strictly increasing sequence.

That is, in the sequence if numbers are decreasing, they can start increasing at one point. Thereafter, they cannot decrease at any point further.

Sequence made up of only increasing numbers or only decreasing numbers is a valid sequence. So, in both the cases, print true.

Sample Input 1 :
5
9
8
4
5
6

Sample Output 1 :
true

Sample Input 2 :
3
1
2
3

Sample Output 2 :
true

Sample Input 3 :
3
8
7
7

Sample Output 3 :
false

Explanation for Sample Format 3 :
8 7 7 is not strictly decreasing, so output is false.

Sample Input 4 :
6
8
7
6
5
8
2

Sample Output 4 :
false

Explanation for Sample Input 4 :
The series is :
8 7 6 5 8 2
It is strictly decreasing first (8 7 6 5). Then it's strictly increasing (5 8). But then it starts strictly decreasing again (8 2). Therefore, the output for this test case is 'false'

*/

#include<iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int prev;
  cin >> prev;

  int count = 2;
  int current ;
  bool isDec = true;
  while (count <= n){
    cin >> current ;
    if(current == prev){
      cout << "false";
      return 0;
    }else if(current < prev){
      if(isDec == false) {
        cout << "false" << endl;
        return 0;
      }
    }else {
      if (isDec == true){
        isDec = false;
      }
    }
    prev = current;
    count++;
  }

  cout << "true" << endl;
}
