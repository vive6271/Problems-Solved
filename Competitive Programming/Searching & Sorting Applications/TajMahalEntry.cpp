#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    // write your code here
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }
    ll multi = INT_MAX, pos = 0;
    for(int i = 0; i < n; i++){
      ll start = 0, end = 1000000000, mid;
      while(start < end){
        mid = (start+end) / 2;
        if(i + (mid*n) >= arr[i]){
          end = mid-1;
          if(multi > mid){
            multi = mid;
            pos = i;
          }
        }else{
          start = mid+1;
        }
      }
    }
    delete [] arr;
    cout << pos+1 << endl;
    return 0;
}
