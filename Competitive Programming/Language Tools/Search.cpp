#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int arr[] = {1, 3, 4, 5, 9, 13, 17};
  cout << binary_search(arr, arr+7, 9) << endl; // gives output true or false
  cout << binary_search(arr, arr+7, 19) << endl;

  cout << lower_bound(arr, arr+7, 9) - arr << endl; // it gives us memory address of 9. So to find its index we have to subtract with starting memory address of arr
  cout << upper_bound(arr, arr+7, 9) - arr << endl;
}
