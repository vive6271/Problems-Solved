#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

struct Point{
  int x, y;
};

int toChange(Point p, Point q, Point r){
  int value = (q.y - p.y)*(r.x - q.x) - (q.x - p.x)*(r.y - q.y);
  if(value == 0){
    return 0;
  }
  return ((value > 0) ? 1 : 2);
}

void convexHull(Point* points, int n){
  if(n < 3){
    return;
  }
  vector<Point> hull;
  int left = 0;
  for(int i = 1; i < n; i++){
    if(points[i].x < points[left].x){
      left = i;
    }
  }
  int p = left;

  do{
    hull.push_back(points[p]);
    int q = (p+1) % n;
    for(int i = 0; i < n; i++){
      if(toChange(points[p], points[i], points[q]) == 2){
        q = i;
      }
    }
    p = q;
  }while(p != left);

  for(int i = 0; i < hull.size(); i++){
    cout << hull[i].x << " " << hull[i].y << endl;
  }
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  Point* points = new Point[n];
  for(int i = 0; i < n; i++){
    cin >> points[i].x;
  }
  for(int i = 0; i < n; i++){
    cin >> points[i].y;
  }
  convexHull(points, n);
  delete [] points;
  return 0;
}
