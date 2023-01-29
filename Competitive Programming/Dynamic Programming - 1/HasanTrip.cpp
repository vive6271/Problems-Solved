#include<bits/stdc++.h>
using namespace std;

double dist(pair<double, double> &p1, pair<double, double> &p2){
  double a = (p2.first - p1.first) * (p2.first - p1.first);
  double b = (p2.second - p1.second) * (p2.second - p1.second);
  return sqrt(a+b);
}

double husanTrip(pair<double, double> *point, int n, double *happy){
  double *output = new double[n];
  output[0] = happy[0];
  for(int i = 1; i < n; i++){
    output[i] = INT_MIN;
    for(int j = 0; j < i; j++){
      double x = dist(point[i],point[j]);
      output[i] = max(output[i], output[j] - x);
    }
    output[i] += happy[i];
  }
  return output[n-1];
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    pair<double, double> *point = new pair<double, double>[n];
    double *happy = new double[n];
    for(int i = 0; i < n; i++){
      cin >> point[i].first >> point[i].second >> happy[i];
    }
    cout << fixed;
    cout << setprecision(6) << husanTrip(point,n,happy) << endl;
    delete [] point;
    delete [] happy;
  }
  return 0;
}
