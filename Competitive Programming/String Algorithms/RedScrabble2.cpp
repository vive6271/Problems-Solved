#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int cnt[2000005][3];
int sum[2000005];
string s;
ll answer = 0;

string daniTrick(string s){
    string dani = "";
    int n = s.length();
    for (int i = 0; i < n; ++i){
        dani += '@';
        dani += s[i];
    }
    return dani + '@';
}

int cal(int l, int r, int y){
    if (l > r)
        return 0;
    if (l > 0){
        int total = (sum[l - 1] + y) % 3;
        return cnt[r][total] - cnt[l - 1][total];
    }
    return cnt[r][y];
}

void prepare(string s){
    memset(cnt, 0, sizeof(cnt));
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i < s.length(); ++i){
        sum[i] = sum[i - 1];
        if (s[i] != '@'){
            sum[i] += (s[i] - '0');
            sum[i] %= 3;
        }
        for (int j = 0; j < 3; ++j){
            cnt[i][j] = cnt[i - 1][j];
        }
        if (s[i] != '@' && s[i] != '0')
            cnt[i][sum[i]]++;
    }
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    s = daniTrick(s);
    int n = s.length();
    vector<int> dp(n, 0);
    prepare(s);

    int l = 0, r = -1;

    for (int i = 0; i < n; ++i){
        int k;
        if (i > r)
            k = 1;
        else
            k = min(r - i, dp[r - i + l]);
        while (i - k >= 0 && i + k < n && s[i - k] == s[i + k])
            k++;
        k--;
        dp[i] = k;
        if (i + k > r){
            r = i + k;
            l = i - k;
        }
        if (s[i] != '@'){
            answer += cal(i + 1, i + k, (s[i] - '0') % 3);
            if ((s[i] - '0') % 3 == 0)
                ++answer;
        }else{
            answer += cal(i + 1, i + k, 0);
        }
    }
    cout << answer << endl;
    return 0;
}
