#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Node{
public:
  int height;
  int width;
};

bool compare(Node n1, Node n2){
  return n1.height > n2.height;
}

int main(){
  int n;
  cin >> n;
  Node *arr = new Node[n];
  for(int i = 0; i < n; i++){
    int w, h;
    cin >> w >> h;
    arr[i].height = h;
    arr[i].width = w/2;
  }
  sort(arr, arr+n, compare);
  ll totalArea = 0, lastWidth = 0;
  for(int i = 0; i < n; i++){
    if(arr[i].width > lastWidth){
      totalArea += (arr[i].width - lastWidth) * arr[i].height;
      lastWidth = arr[i].width;
    }
  }
  cout << 2*totalArea << endl;
  delete [] arr;
  return 0;
}
