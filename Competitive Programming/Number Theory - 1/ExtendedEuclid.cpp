#include<iostream>
using namespace std;

class Triplet{
public:
  int x;
  int y;
  int gcd;
};

Triplet extendedEuclid(int a, int b){
  //Base Case
  if(b == 0){
    Triplet ans;
    ans.x = 1;
    ans.y = 0;
    ans.gcd = a;
    return ans;
  }

  Triplet smallAns = extendedEuclid(b, a % b);
  Triplet ans;
  ans.x = smallAns.y;
  ans.y = (smallAns.x - ((a/b) * smallAns.y));
  ans.gcd = smallAns.gcd;
  return ans;
}

int main(){
  int a,b;
  cin >> a >> b;
  Triplet ans = extendedEuclid(a,b);
  cout << "X : " << ans.x << " | Y : " << ans.y << " | GCD : " << ans.gcd << endl;
  return 0;
}
