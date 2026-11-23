#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, a, b, c;

    static int dp[40001];
    memset(dp, -0x3f, sizeof dp);
    dp[0] = 0;

    static int kk[3];
    int pos = 0;

    cin >> n >> kk[pos ++] >> kk[pos ++] >> kk[pos ++];



    #define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

    FOR(i, 1, n) FOR(j, 0, 2) if(i >= kk[j]) {
        dp[i] = max(dp[i], dp[i - kk[j]] + 1);
    }

    cout << dp[n];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    // cin >> t

    while(t --) solve();
    
    return 0;
}