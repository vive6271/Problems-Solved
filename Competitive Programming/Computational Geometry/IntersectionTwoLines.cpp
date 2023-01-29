#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pd pair<double,double>

pd checkIntersection(pd A, pd B, pd C, pd D){
   // Line AB represented as a1x + b1y = c1
  double a1 = B.second - A.second;
  double b1 = A.first - B.first;
  double c1 = a1*(A.first) + b1*(A.second);

  // Line CD represented as a2x + b2y = c2
  double a2 = D.second - C.second;
  double b2 = C.first - D.first;
  double c2 = a2*(C.first) + b2*(C.second);

  double determinant = a1*b2 - a2*b1;
  if(determinant == 0){
    return make_pair(FLT_MAX,FLT_MAX);
  }else{
    double x = (b2*c1 - b1*c2) / determinant;
    double y = (a1*c2 - a2*c1) / determinant;
    return make_pair(x,y);
  }
}

int32_t main(){
  pd A = make_pair(1,1);
  pd B = make_pair(4,4);
  pd C = make_pair(1,8);
  pd D = make_pair(2,4);

  pd interSection = checkIntersection(A, B, C, D);
  if(interSection.first == FLT_MAX && interSection.second == FLT_MAX){
    cout << "The given lines AB and CD are Parallel" << endl;
  }else{
    cout << "The InterSection of the given lines AB and CD is : " << "(" << interSection.first << "," << interSection.second << ")" << endl;
  }
  return 0;
}
