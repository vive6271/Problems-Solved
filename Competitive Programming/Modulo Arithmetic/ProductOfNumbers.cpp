#include<bits/stdc++.h>
using namespace std;
int main(){
    // write your code here
    int t, mod;
    cin >> t;
    mod = pow(10,9)+7;
    while(t--){
        int n, ans = 1;
        cin >> n;
        for(int i = 1; i <= n; i++){
            long a = (long) ans*i;
            ans = a % mod;
        }
        cout << ans << endl;
    }
    return 0;
}
