#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

class Point{
public:
  int x, y;
};

class Polygon{
public:
  Point* points;
  Polygon(int n){
    points = new Point[n];
  }
};

int areaPolygon(Polygon &p, int n){
  int fArea = 0;
  for(int i = 1; i < n-1; i++){
    int a1 = p.points[i].x - p.points[0].x;
    int b1 = p.points[i].y - p.points[0].y;
    int a2 = p.points[i+1].x - p.points[0].x;
    int b2 = p.points[i+1].y - p.points[0].y;
    fArea += ((a1*b2) - (a2*b1));
  }
  return abs(fArea/2);
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    Polygon p(n);
    for(int i = 0; i < n; i++){
      cin >> p.points[i].x;
      cin >> p.points[i].y;
    }
    cout << areaPolygon(p,n) << endl;
  }
  return 0;
}
