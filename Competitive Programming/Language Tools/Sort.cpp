#include<iostream>
#include<algorithm>
using namespace std;

struct Interval{
  int start;
  int end;
};


bool compare(Interval i1, Interval i2){
  //return i1.start > i2.start; // for decreasing order of start 
  return i1.start < i2.start; // for increasing order of start
}
int main(){
  int arr[] = {1,5,3,2,4};
  //sort(arr,arr+5); for increasing order
  sort(arr, arr+5, greater<int>()); // for decreasing order
  //sort(arr+2, arr+5); // for specific sort
  for(int i = 0; i < 5; i++){
    cout << arr[i] << " ";
  }
  cout << endl;

  Interval arr2[] = {{6,4}, {3,4}, {4,6}, {8,13}, {5,10}};
  sort(arr2, arr2+5, compare);
  for(int i = 0; i < 5; i++){
    cout << arr2[i].start << " : " << arr2[i].end << endl;
  }
  return 0;
}
