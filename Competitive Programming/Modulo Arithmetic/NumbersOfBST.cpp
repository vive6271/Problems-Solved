#include<bits/stdc++.h>
using namespace std;
//Note :- "Compiler problem" gives wrong answers
/*
int balancedBST(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    int m = pow(10,9) + 7;
    int x = balancedBST(n-1);
    int y = balancedBST(n-2);

    long a = (long) x*x;
    long b = (long) 2*x*y;

    int ans1 = (int) (a%m);
    int ans2 = (int) (b%m);
    int ans = (ans1+ans2) % m;
    return ans;
}
*/
int mod = pow(10,9) + 7;
int balancedBST(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    int x = balancedBST(n-1);
    int y = balancedBST(n-2);

    return ((((long) x*x) % mod) + (((long) 2*x*y) % mod)) % mod;
}

int main(){

    // write your code here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << balancedBST(n) << endl;
    }
    return 0;
}
