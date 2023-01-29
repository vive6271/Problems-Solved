#include<bits/stdc++.h>
using namespace std;

class Coder{
public:
  int x, y, index;
};

bool compare(Coder c1, Coder c2){
  if(c1.x == c2.x){
    return c1.y < c2.y;
  }
  return c1.x < c2.x;
}

void update(int y, int *bit){
  for(; y <= 100000; y += (y&(-y))){
    bit[y]++;
  }
}

int query(int y, int *bit){
  int count = 0;
  for(; y > 0; y -= (y&(-y))){
    count += bit[y];
  }
  return count;
}

int main(){
  int n;
  cin >> n;
  Coder *arr = new Coder[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i].x >> arr[i].y;
    arr[i].index = i;
  }
  sort(arr, arr+n, compare);
  int *bit = new int[100001]();
  int *ans = new int[n]();
  int i = 0;
  while(i < n){
    int endIndex = i;
    while(endIndex < n && arr[i].x == arr[endIndex].x && arr[i].y == arr[endIndex].y){
      endIndex++;
    }

    //query
    for(int j = i; j < endIndex; j++){
      ans[arr[j].index] = query(arr[j].y, bit);
    }

    //update
    for(int j = i; j < endIndex; j++){
      update(arr[j].y, bit);
    }
    i = endIndex;
  }
  for(int i = 0; i < n; i++){
    cout << ans[i] << endl;
  }
  delete [] arr;
  delete [] bit;
  delete [] ans;
  return 0;
}
