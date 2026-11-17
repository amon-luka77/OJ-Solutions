#include<bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

const int maxN = 5e5;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;

        int n, m;
        cin >> n;
        vector<int> a(n + 1, 0);
        FOR(i, 1, n) cin >> a[i];
        cin >> m;
        vector<int> b(m + 1, 0);
        FOR(i, 1, m) cin >> b[i];

        vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));
        vector<ll> dpB(t + 1);


        dp[0][0] = 1;
        FOR(i, 1, n) FOR(j, 0, t) {
            dp[i][j] = dp[i - 1][j];
            if(j >= a[i]) dp[i][j] |= dp[i - 1][j - a[i]];
        }

        #define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i --)

        FOR(i, 1, m) FORD(j, t, 0) if(j >= b[i]) dpB[j] = max(dpB[j], dpB[j - b[i]] + 1);

        ll res = 0;
        ll sum = 0;

        FOR(i, 0, n) {
            sum += a[i];
            FOR(j, 0, t) if(dp[i][j]) {
                ll b = sum - j;
                if(b <= t) res = max(res, i + dpB[t - b]);
            }
        }

        cout << res;
}
