#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

struct Point{
  int x, y;
};

bool toChange(Point p, Point q, Point r){
  int x1 = q.x - p.x;
  int y1 = q.y - p.y;
  int x2 = r.x - q.x;
  int y2 = r.y - q.y;

  int value = x1*y2 - x2*y1;
  return value > 0;
}

void convexHull(Point points[], int n){
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
      if(toChange(points[p], points[q], points[i])){
        q = i;
      }
    }
    p = q;
  }while(p != left);

  for(int i = 0; i < hull.size(); i++){
    cout << hull[i].x << "," << hull[i].y << endl;
  }
}

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  Point points[] = {{0,4},{1,1},{2,2},{4,0},{4,4},{0,0},{3,3}};
  convexHull(points, 7);
  return 0;
}
