#include<bits/stdc++.h>
using namespace std;

int mod = pow(10,9)+7;

int power(int x, int y){
    if(y == 0){
        return 1;
    }
    return ((long) x * power(x,y-1)) % mod;
}

int main(){
    // write your code here
    int t;
    cin >> t;
    while(t--){
        int x,y;
        cin >> x >> y ;
        cout << power(x,y) << endl;
    }
    return 0;
}
